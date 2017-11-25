#include "TitleScreen.h"



TitleScreen::TitleScreen()
{
}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::LoadContent()
{
	if (!font.loadFromFile("Resources/Font/Games.ttf"))
		std::cout << "Title Screen: Cound not load font" << std::endl;

	text.setFont(font);
	text.setString("Title Screen");
}

void TitleScreen::UnloadContent()
{

}

void TitleScreen::Update(sf::Keyboard::Key key)
{

}

void TitleScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
}

