#pragma once

#include <SFML/Network.hpp>
#include <thread>
#include <iostream>

class Network
{
public:
	Network();
	~Network();

	void Init(); // Connect

	// TCP
	void TCP_Init(); // TCP Connect
	void TCP_Receive(); // TCP Receive

	void TCP_Send(std::string buffer_out);
	void TCP_Send_Message(std::string buffer_out);

private:
	sf::TcpSocket tcp_socket;
	//sf::UdpSocket udp_socket;

	std::thread tcp_receive;
	//std::thread udp_receive;

	sf::IpAddress recipient = "127.0.0.1";
	//unsigned short UDP_port_ = 8080;

	//// Players
	////std::string local_username{ "batman" };
	////OnlineData* onlinedata{ nullptr };

	//// Other
	bool isConnected{ false };
	////bool registered{ false };

};

