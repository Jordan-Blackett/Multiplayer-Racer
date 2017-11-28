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

class Text
{
public:
	//void init(sf::Vector2i pos, sf::Vector2i size, int fontSize);
	//void IsClicked(sf::Vector2i mousePos);
	//void inputText(sf::RenderWindow &Window, sf::Event &event);
	//void render(sf::RenderWindow &Window);
private:
	//sf::Font font;
	//sf::Text txt;
	//std::string text;
	//sf::Vector2i txtPosition;
	//sf::RectangleShape txtBox;
	//sf::IntRect txtRect;
	//sf::Color activeColor = sf::Color(255, 255, 255, 150);
	//sf::Color notActiveColor = sf::Color(255, 255, 255, 25);
	//bool active{ false };
};

class TextBox
{
public:
	void init(sf::Vector2i pos, sf::Vector2i size, int fontSize);
	void IsClicked(sf::Vector2i mousePos);
	void inputText(sf::RenderWindow &Window, sf::Event &event);
	void render(sf::RenderWindow &Window);
private:
	sf::Font font;
	sf::Text txt;
	std::string text;
	sf::Vector2i txtPosition;
	sf::RectangleShape txtBox;
	sf::IntRect txtRect;
	sf::Color activeColor = sf::Color(255, 255, 255, 150);
	sf::Color notActiveColor = sf::Color(255, 255, 255, 25);
	bool active{ false };
};
