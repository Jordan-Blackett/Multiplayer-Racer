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
	void Register();

	// TCP
	void TCP_Init(); // TCP Connect
	void TCP_Receive(); // TCP Receive

	void TCP_Send(std::string buffer_out);
	void TCP_Send_Message(std::string buffer_out);

	// UDP
	void UDP_Receive();
	void UDP_Send(std::string buffer_out);

	//
	void SetIPAddress(std::string ip) { recipient = ip; }
	void SetTCPPort(std::string port) { TCP_port = atoi(port.c_str()); }
	void SetLocalUsername(std::string name) { local_username = name; }

	//
	bool GetIsConnected() { return isConnected; }
	std::string GetStatus() { return statusTxt; }

private:
	sf::TcpSocket tcp_socket;
	sf::UdpSocket udp_socket;

	std::thread tcp_receive;
	std::thread udp_receive;

	sf::IpAddress recipient = "192.168.0.10";
	sf::IpAddress rec = sf::IpAddress::getLocalAddress();
	unsigned short TCP_port = 8080;
	unsigned short UDP_port = 8080;

	// Players
	std::string local_username{ "batman" };
	////OnlineData* onlinedata{ nullptr };

	//// Other
	bool isConnected{ false };
	bool isRegistered{ false };
	std::string statusTxt{ "Connecting" };

};

