#pragma once

#include <vector>

//class MessageManager
//{
//public:
//	MessageManager();
//	~MessageManager();
//};

// Point and dir eg: Projectile
struct VectorMessage
{
	float x1;
	float x2;
	float y1;
	float y2;
};
class VectorListener;
class VectorSender
{
public:
	VectorSender();
	~VectorSender();

	void SendMessage(float x1, float y1, float x2, float y2);
	void recieveListener(VectorListener * listener);

private:
	std::vector<VectorListener*> listeners;
};

class VectorListener
{
public:
	VectorListener();
	~VectorListener();

	void ListenToSender(VectorSender* sender);
	std::vector<float> GetMessage();

	void recieveMessage(VectorMessage message);

private:
	std::vector<VectorMessage> messages;
};