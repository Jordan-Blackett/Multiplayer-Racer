#include "Network.h"



Network::Network()
{
}


Network::~Network()
{
}

void Network::Init() {
	std::cout << "Network Init" << std::endl;
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
			std::cout << s << std::endl;
			//tcp_queue.push(s);
		}
	}
}

void Network::TCP_Send(std::string buffer_out) {
	// TCP socket send
	if (tcp_socket.send(buffer_out.c_str(), buffer_out.size()) != sf::Socket::Done) {
		std::cerr << "sending failed\n" << std::endl;
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