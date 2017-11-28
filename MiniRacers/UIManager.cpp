#include "UIManager.h"



UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

void Button::init(sf::Vector2i btnPos, std::string btnString)
{
	btnPosition = btnPos;

	if (!btnTexture.loadFromFile(btnString)) {}

	btnSprite.setTexture(btnTexture);
	btnSprite.setPosition(sf::Vector2f(btnPosition));

	// Btn Rect
	btnRect = sf::IntRect(btnPosition, sf::Vector2i(btnTexture.getSize().x, btnTexture.getSize().y));
}

bool Button::IsClicked(sf::Vector2i mousePos)
{
	if (btnRect.contains(mousePos.x, mousePos.y))
		return true;
	else
		return false;
}

void Button::render(sf::RenderWindow &Window)
{
	Window.draw(btnSprite);
}

void TextBox::init(sf::Vector2i pos, sf::Vector2i size, int fontSize)
{
	txtPosition = pos;
	
	if (!font.loadFromFile("Resources/Font/Games.ttf"))
		std::cout << "Title Screen: Cound not load font" << std::endl;

	txt.setFont(font);
	txt.setString("");
	txt.setCharacterSize(fontSize);

	txt.setPosition(sf::Vector2f(txtPosition));

	txtBox.setFillColor(notActiveColor);
	txtBox.setSize(sf::Vector2f(size));
	txtBox.setPosition(sf::Vector2f(txtPosition));

	// Btn Rect
	txtRect = sf::IntRect(txtPosition, sf::Vector2i(size.x, size.y));
}

void TextBox::IsClicked(sf::Vector2i mousePos)
{
	if (txtRect.contains(mousePos.x, mousePos.y))
	{
		active = true;
		txtBox.setFillColor(activeColor);
	}
	else
	{
		active = false;
		txtBox.setFillColor(notActiveColor);
	}
}

void TextBox::inputText(sf::RenderWindow &Window, sf::Event &event)
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	//{
	//	active = true;
	//}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if (active) {
			//text.clear();
			active = false;
			txtBox.setFillColor(notActiveColor);
		}
	}

	if (active) {
		while (Window.pollEvent(event)) {
			//if (event.type == sf::Event::KeyPressed)
			//{
			//	if (event.key.code == sf::Keyboard::Return) 
			//	{
			//		text.clear();
			//		std::cout << "CLEAR" << std::endl;
			//		return;
			//	} 
			//}
				
			if (event.type == sf::Event::TextEntered) {
				if (event.KeyPressed == sf::Keyboard::BackSpace && text.size() != 0) {
					text.pop_back();
					//std::cout << text << std::endl;
				}
				else if (event.text.unicode < 128) {
					text.push_back((char)event.text.unicode);
					//std::cout << text << std::endl;
				}
			}
		}
	}
}

void TextBox::render(sf::RenderWindow & Window)
{
	//if (active)
	//{
		Window.draw(txtBox);
		txt.setString(text);
		Window.draw(txt);
	//}
}
