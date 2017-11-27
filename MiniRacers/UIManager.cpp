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
