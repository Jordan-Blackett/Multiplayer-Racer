#pragma once

#include <vector>
#include<SFML\Graphics.hpp>

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Update(sf::Keyboard::Key key);

	bool KeyPressed(sf::Keyboard::Key key);
	bool KeyPressed(std::vector<int> keys);

	bool KeyReleased(int key);
	bool KeyReleased(std::vector<int> keys);

	bool KeyDown(sf::Keyboard::Key key);
	//bool KeyDown(std::vector<sf::Keyboard::Key> keys);

private:
	sf::Keyboard::Key inputKey;
};

