#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class UIManager
{
public:
	UIManager();
	~UIManager();
};

class Button
{
public:
	void init(sf::Vector2i btnPos, std::string btnString);
	bool IsClicked(sf::Vector2i mousePos);
	void render(sf::RenderWindow &Window);
private:
	sf::Vector2i btnPosition;
	sf::Texture btnTexture;
	sf::Sprite btnSprite;
	sf::IntRect btnRect;
};
