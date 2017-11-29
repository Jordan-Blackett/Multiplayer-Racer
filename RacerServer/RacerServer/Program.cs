using System;
using System.Net; // IPAddress
using System.Net.Sockets; // For TcpListener, TcpClient
using System.Threading;
using System.Text;
using System.Collections.Generic;
using Google.Protobuf;
using Google.Protobuf.Examples.AddressBook;
using static Google.Protobuf.Examples.AddressBook.Person.Types;
//using Google.Protobuf.MessageExtensions;

//namespace Google.Protobuf.Examples.AddressBook
//{
//    Person batman = new Person
//    {
//        Id = 1234,
//        Name = "John Doe",
//        Email = "jdoe@example.com",
//        Phones = { new PhoneNumber { Number = "555-4321", Type = PhoneType.HOME } }
//    };
//}

namespace RacerServer
{
    //Person batman = new Person
    //{
    //    //Id = 1234,
    //    //Name = "John Doe",
    //    //Email = "jdoe@example.com",
    //    //Phones = { new Person.Types.PhoneNumber { Number = "555-4321", Type = Person.Types.PhoneType.HOME } }
    //}




    // IDK
    //syntax = "proto3";
    //package tutorial;

    ////syntax = "proto3";
    ////package tutorial;

    //message Person
    //// {
    //// //    //string name = 1;
    //// //    //int32 id = 2;  // Unique ID number for this person.
    //// //    //string email = 3;
    // }
    //Person john = new Person
    //{
    //    Id = 1234,
    //    Name = "John Doe",
    //    Email = "jdoe@example.com",
    //    Phones = { new Person.Types.PhoneNumber { Number = "555-4321", Type = Person.Types.PhoneType.HOME } }
    //};

    // ----- TCP -----

    // State object for reading client data asynchronously  
    public class StateObject
    {
        // Client  socket.  
        public Socket workSocket = null;
        // Size of receive buffer.  
        public const int BufferSize = 1024;
        // Receive buffer.  
        public byte[] buffer = new byte[BufferSize];
        // Received data string.  
        public StringBuilder sb = new StringBuilder();
    }

    public class AsynchronousSocketListener
    {
        // Thread signal.  
        public static ManualResetEvent allDone = new ManualResetEvent(false);

        public AsynchronousSocketListener()
        {
        }

        public static void StartListening()
        {
            // Data buffer for incoming data.  
            byte[] bytes = new Byte[1024];

            // Establish the local endpoint for the socket.  
            // The DNS name of the computer  
            // running the listener is "host.contoso.com".  
            IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            IPAddress ipAddress = ipHostInfo.AddressList[3];
            int port = 8080;
            Console.WriteLine("IP: " + ipAddress + " Port: " + port);
            IPEndPoint localEndPoint = new IPEndPoint(ipAddress, 8080);

            // Create a TCP/IP socket.  
            Socket listener = new Socket(ipAddress.AddressFamily,
                SocketType.Stream, ProtocolType.Tcp);

            // Bind the socket to the local endpoint and listen for incoming connections.  
            try
            {
                listener.Bind(localEndPoint);
                listener.Listen(100);

                while (true)
                {
                    // Set the event to nonsignaled state.  
                    allDone.Reset();

                    // Start an asynchronous socket to listen for connections.  
                    Console.WriteLine("Waiting for a connection...");
                    listener.BeginAccept(
                        new AsyncCallback(AcceptCallback),
                        listener);

                    // Wait until a connection is made before continuing.  
                    allDone.WaitOne();
                }

            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            Console.WriteLine("\nPress ENTER to continue...");
            Console.Read();

        }

        public static void AcceptCallback(IAsyncResult ar)
        {
            Console.WriteLine("Connection made");

            // Signal the main thread to continue.  
            allDone.Set();

            // Get the socket that handles the client request.  
            Socket listener = (Socket)ar.AsyncState;
            Socket handler = listener.EndAccept(ar);

            // Create the state object.  
            StateObject state = new StateObject();
            state.workSocket = handler;
            handler.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0,
                new AsyncCallback(ReadCallback), state);
        }

        public static void ReadCallback(IAsyncResult ar)
        {

            String content = String.Empty;

            // Retrieve the state object and the handler socket  
            // from the asynchronous state object.  
            StateObject state = (StateObject)ar.AsyncState;
            Socket handler = state.workSocket;

            // Read data from the client socket.   
            int bytesRead = handler.EndReceive(ar);

            if (bytesRead > 0)
            {
                // There  might be more data, so store the data received so far.  
                state.sb.Append(Encoding.ASCII.GetString(
                    state.buffer, 0, bytesRead));

                // Check for end-of-file tag. If it is not there, read   
                // more data.  
                content = state.sb.ToString();
                if (content.IndexOf("<EOF>") > -1)
                {
                    // All the data has been read from the   
                    // client. Display it on the console.  
                    Console.WriteLine("Read {0} bytes from socket. \n Data : {1}",
                        content.Length, content);

                    // -----
                    if (content == "Register")
                    {
                        //string username = "batman";
                        //ClientObject client;
                        //clients.Add(username, client);
                    }

                    Position pos = new Position
                    {
                        Id = 1775,
                        Username = "Batman",
                        PosX = 100,
                        PosY = 100
                    };

                    Person john = new Person
                    {
                        Id = 1234,
                        Name = "John Doe",
                        Email = "jdoe@example.com",
                        Phones = { new Person.Types.PhoneNumber { Number = "555-4321", Type = Person.Types.PhoneType.Home } }
                    };


                    Send(handler, pos.ToString());

                    // -----

                    // Echo the data back to the client.  
                    //Send(handler, content);
                }
                else
                {
                    // Not all data received. Get more.  
                    handler.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0,
                    new AsyncCallback(ReadCallback), state);
                }
            }
            //
            state.sb.Clear(); //= new StringBuilder();

            handler.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0,
            new AsyncCallback(ReadCallback), state);
            //
        }

        private static void Send(Socket handler, String data)
        {
            // Convert the string data to byte data using ASCII encoding.  
            byte[] byteData = Encoding.ASCII.GetBytes(data);

            // Begin sending the data to the remote device.  
            handler.BeginSend(byteData, 0, byteData.Length, 0,
                new AsyncCallback(SendCallback), handler);
        }

        private static void SendCallback(IAsyncResult ar)
        {
            try
            {
                // Retrieve the socket from the state object.  
                Socket handler = (Socket)ar.AsyncState;

                // Complete sending the data to the remote device.  
                int bytesSent = handler.EndSend(ar);
                Console.WriteLine("Sent {0} bytes to client.", bytesSent);

                //handler.Shutdown(SocketShutdown.Both);
                //handler.Close();

            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        // ----- UDP -----

        public class UDPState
        {
            public IPEndPoint e;
            public UdpClient u;
        }

        public static int listenPort = 8080;

        public static bool messageReceived = false;
        public static void UDPReceiveCallback(IAsyncResult ar)
        {
            UdpClient u = (UdpClient)((UDPState)(ar.AsyncState)).u;
            IPEndPoint e = (IPEndPoint)((UDPState)(ar.AsyncState)).e;
            Byte[] receiveBytes = u.EndReceive(ar, ref e);
            string receiveString = Encoding.ASCII.GetString(receiveBytes);
            Console.WriteLine("Received: {0}", receiveString);
            // The message then needs to be handled
            messageReceived = true;

            //u.BeginReceive(new AsyncCallback(UDPReceiveCallback), s);

        }

        public static void UDPReceiveMessages()
        {
            // Receive a message and write it to the console.
            IPEndPoint e = new IPEndPoint(IPAddress.Any, listenPort);
            UdpClient u = new UdpClient(e);
            UDPState s = new UDPState();
            s.e = e;
            s.u = u;
            Console.WriteLine("listening for UDP messages");
            u.BeginReceive(new AsyncCallback(UDPReceiveCallback), s);

            // Do some work while we wait for a message.
            while (!messageReceived)
            {
                // Do something
            }
        }

        public static bool messageSent = false;
        public static void UDPSendCallback(IAsyncResult ar)
        {
            UdpClient u = (UdpClient)ar.AsyncState;
            Console.WriteLine("number of bytes sent: {0}", u.EndSend(ar));
            messageSent = true;
        }

        static void UDPSendMessage(string server, string message)
        {
            // create the udp socket
            UdpClient u = new UdpClient();
            u.Connect(server, listenPort);
            Byte[] sendBytes = Encoding.ASCII.GetBytes(message);
            // send the message
            // the destination is defined by the call to .Connect()
            u.BeginSend(sendBytes, sendBytes.Length, new AsyncCallback(SendCallback), u);
            // Do some work while we wait for the send to complete. For
            // this example, we 'll just sleep
            while (!messageSent)
            {
                Thread.Sleep(100);
            }
        }

        // Client
        public struct ClientObject
        {
            //TCP IP
            //TCP Port
            //UDP Port
        }

        // Key - Username; Value - ClientStruct
        Dictionary<string, ClientObject> clients = new Dictionary<string, ClientObject>();

        public static int Main(String[] args)
        {
            //
            Person john = new Person
            {
                Id = 1234,
                Name = "John Doe",
                Email = "jdoe@example.com",
                Phones = { new Person.Types.PhoneNumber { Number = "555-4321", Type = Person.Types.PhoneType.Home } }
            };
            //

            StartListening();
            UDPReceiveMessages();
            return 0;
        }
    }
}
