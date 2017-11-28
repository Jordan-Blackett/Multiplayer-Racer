#include "MessageManager.h"



//MessageManager::MessageManager()
//{
//}
//
//
//MessageManager::~MessageManager()
//{
//}

VectorSender::VectorSender()
{
}

VectorSender::~VectorSender()
{
}

void VectorSender::SendMessage(float x1, float y1, float x2, float y2)
{
	VectorMessage newMessage;
	newMessage.x1 = x1;
	newMessage.y1 = y1;
	newMessage.x2 = x2;
	newMessage.y2 = y2;

	for (unsigned int i = 0; i < listeners.size(); i++)
	{
		listeners[i]->recieveMessage(newMessage);
	}
}

void VectorSender::SendMessage(std::string name, float x2, float y2)
{
}

void VectorSender::recieveListener(VectorListener * listener)
{
	listeners.push_back(listener);
}

VectorListener::VectorListener()
{
}

VectorListener::~VectorListener()
{
}

void VectorListener::ListenToSender(VectorSender* sender)
{
	sender->recieveListener(this);
}

std::vector<float> VectorListener::GetMessage()
{
	std::vector<float> messageVector;

	for (int i = 0; i < messages.size(); i++)
	{
		messageVector.push_back(messages[i].x1);
		messageVector.push_back(messages[i].y1);
		messageVector.push_back(messages[i].x2);
		messageVector.push_back(messages[i].y2);
	}

	messages.clear();

	return messageVector;
}

void VectorListener::recieveMessage(VectorMessage message)
{
	messages.push_back(message);
}
