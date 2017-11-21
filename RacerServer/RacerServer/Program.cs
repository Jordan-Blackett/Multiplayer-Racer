using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace RacerServer
{
    //class Program
    //{
    public class Tcp_Listen
    {
        // Size of receive buffer
        private const int BUFSIZE = 32;

        // TcpEchoServer
        static void Main(string[] args)
        {
            Console.WriteLine("Starting echo server.");

            // Test for correct # of args
            if (args.Length > 1)
            {
                throw new ArgumentException("Parameters: [<Port>]");
            }

            int port = (args.Length == 1) ? Int32.Parse(args[0]) : 8080;

            TcpListener listener = null;
            try
            {
                // Create a TCPListener to accept client connections
                listener = new TcpListener(IPAddress.Any, port);
                listener.Start();
            }
            catch (SocketException se)
            {
                Console.WriteLine(se.ErrorCode + ": " + se.Message);
                Environment.Exit(se.ErrorCode);
            }

            byte[] rcvBuffer = new byte[BUFSIZE]; // Receive buffer
            int bytesRcvd; // Received byte count


            // Run forever, accepting and servicing connections
            for (;;)
            {
                //Console.WriteLine(IPAddress.Any);
                TcpClient client = null;
                NetworkStream netStream = null;

                try
                {
                    // Get client connection
                    client = listener.AcceptTcpClient();
                    netStream = client.GetStream();
                    Console.Write("Handling client - ");

                    // Receive until client closes connection, indicated by 0 return value
                    int totalBytesEchoed = 0;
                    while ((bytesRcvd = netStream.Read(rcvBuffer, 0, rcvBuffer.Length)) > 0)
                    {
                        netStream.Write(rcvBuffer, 0, bytesRcvd); // Reply
                        Console.WriteLine("Reply - " + rcvBuffer[0]);
                        totalBytesEchoed += bytesRcvd;

                    }

                    Console.WriteLine("echoed {0} bytes.", totalBytesEchoed);

                    // Close the stream and socket. We are done with this client
                    netStream.Close();
                    client.Close();

                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                    netStream.Close();
                }
            }
        }

        public class Tcp_EchoClient
        {

        }

    }
}
