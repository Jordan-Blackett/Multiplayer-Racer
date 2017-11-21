#include "Network.h"



Network::Network()
{
}


Network::~Network()
{
}

void Network::Init() {
	TCP_Init();
	//udp_receive_ = std::thread(&Networking::UDP_Receive, this);
}

void Network::TCP_Init() {
	while (!isConnected) 
	{
		// TCP socket
		sf::Socket::Status status = tcp_socket.connect(recipient, 8080);
		if (status != sf::Socket::Done) {
			// Error
			std::cerr << "TCP: Connect Failed\n";
		} else {
			// Connect Successful
			std::cout << "TCP: Connect Successful" << std::endl;
			tcp_receive = std::thread(&Network::TCP_Receive, this);
			isConnected = true;
			//Register();
		}
	}
}

void Network::TCP_Receive() {
	char buffer_in[1024];

	while (1)
	{
		std::memset(buffer_in, 0, sizeof buffer_in);
		std::size_t received;

		// TCP socket receive
		if (tcp_socket.receive(buffer_in, 100, received) != sf::Socket::Done) {
			std::cerr << "Received failed" << std::endl;
		}

		std::string s(buffer_in);
		if (s == "stop") {
			std::cerr << " TCP: Received stopping" << std::endl;
			break;
		}
		else {
			//tcp_queue.push(s);
		}
	}
}