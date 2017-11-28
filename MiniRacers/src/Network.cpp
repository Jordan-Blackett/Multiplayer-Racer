#include "Network.h"



Network::Network()
{
}


Network::~Network()
{
}

void Network::Init() {
	std::cout << "Network Init - IP: " << recipient << " Port: " << TCP_port << std::endl;
	//recipient = rec;
	TCP_Init();
}

void Network::TCP_Init() {
	//while (!isConnected)
	//{
		statusTxt = "Connecting";
		// TCP socket
		sf::Socket::Status status = tcp_socket.connect(recipient, TCP_port);
		if (status != sf::Socket::Done) {
			// Error
			std::cerr << "TCP: Connect Failed\n";
			statusTxt = "Connection Failed";
		} else {
			// Connect Successful
			std::cout << "TCP: Connect Successful" << std::endl;
			isConnected = true;
			statusTxt = "Connected";

			//tcp_receive = std::thread(&Network::TCP_Receive, this);
			//Register();

			//udp_receive = std::thread(&Network::UDP_Receive, this);
		}
	//}
}

void Network::Register() {
	std::string buffer_out = "register::" + local_username;
	TCP_Send(buffer_out);
	std::cout << "Network: Register " + local_username << std::endl;
}

void Network::TCP_Receive() {
	std::cout << "TCP: Receive started" << std::endl;
	char buffer_in[1024];

	while (1)
	{
		std::memset(buffer_in, 0, sizeof buffer_in);
		std::size_t received;

		// TCP socket receive
		if (tcp_socket.receive(buffer_in, 100, received) != sf::Socket::Done) {
			std::cerr << "Received failed" << std::endl;
            return;
		}

		std::string s(buffer_in);

		if (s == "stop") {
			std::cerr << " TCP: Received stopping" << std::endl;
			break;
		}
		else {
			std::cout << "TCP: Received '" + s + "'" << std::endl;
			//tcp_queue.push(s);
		}
	}
}


void Network::TCP_Send(std::string buffer_out) {
	// TCP socket send
	if (tcp_socket.send(buffer_out.c_str(), buffer_out.size()) != sf::Socket::Done) {
		std::cerr << "sending failed\n" << std::endl;
	}
    else
    {
        std::cout << "TCP: Sent '" + buffer_out + "' Successful" << std::endl;
    }
}

void Network::TCP_Send_Message(std::string buffer_out) {
	//std::string buffer_out;
	//for (int i = 0; i < onlinedata_->numOfConnectedPlayers; i++) {
	//	buffer_out = "send_chat_message::hey::" + onlinedata_->usernames_[i] + "::" + local_username_;
	//	TCP_Send(buffer_out);
	//}
	//buffer_out = "send_chat_message::hey::" + local_username_ + "::" + local_username_;
	//TCP_Send(buffer_out);
}

// UDP
void Network::UDP_Receive() {
	std::cout << "UDP: Receive started" << std::endl;
	char buffer_in[1024];
	udp_socket.setBlocking(true);

	// UDP socket receive
	while (1)
	{
		std::size_t received;
		std::memset(buffer_in, 0, sizeof buffer_in);
		sf::IpAddress sender;
		unsigned short port_s;

		if (udp_socket.receive(buffer_in, 100, received, sender, port_s) != sf::Socket::Done) {
			//std::cerr << "Udp receive failed." << std::endl;
		}

		std::string s(buffer_in);
		if (s == "stop") {
			std::cerr << " UDP: Received stopping" << std::endl;
			break;
		}
		else if (s != "") {
			//udp_queue_.push(s);
		}
	}
}

void Network::UDP_Send(std::string buffer_out) {
	// UDP socket send
	if (udp_socket.send(buffer_out.c_str(), buffer_out.size(), recipient, UDP_port) != sf::Socket::Done) {
		std::cerr << "UDP: sending failed." << std::endl;
	}
	else
	{
		std::cout << "UDP: Sent '" + buffer_out << std::endl;
	}
}