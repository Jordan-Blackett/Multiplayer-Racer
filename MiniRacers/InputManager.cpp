#include "InputManager.h"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::Update(sf::Keyboard::Key key)
{
	inputKey = key;
}

bool InputManager::KeyPressed(sf::Keyboard::Key key) {
	if (inputKey == key)
		return true;
	else
		return false;
}

bool InputManager::KeyPressed(std::vector<int> keys)
{
	//for (int i = 0; i < keys.size(); i++)
	//{
	//	if (inputEvent.key.code == keys[i])
	//		return true;
	//}
	return false;
}

bool InputManager::KeyReleased(int key)
{
	//if (inputEvent.key.code == key && sf::Event::KeyReleased)
	//	return true;
	//else
		return false;
}

bool InputManager::KeyReleased(std::vector<int> keys)
{
	//for (int i = 0; i < keys.size(); i++)
	//{
	//	if (inputEvent.key.code == keys[i] && sf::Event::KeyReleased)
	//		return true;
	//}
	return false;
}

bool InputManager::KeyDown(sf::Keyboard::Key key)
{
	//if (sf::Keyboard::isKeyPressed(key))
	//	return true;
	//else
		return false;
}

//bool InputManager::KeyDown(std::vector<int> keys)
//{
//
//}