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
	
	// Buttons
	startBtn.init(sf::Vector2i(400,400), "Resources/Button/Start.png");
}

void TitleScreen::UnloadContent()
{

}

void TitleScreen::Update(sf::RenderWindow &Window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i position = sf::Mouse::getPosition(Window);
		if (startBtn.IsClicked(position))
		{
			//ScreenManager::GetInstance()->AddScreen(new GameScreen);
		}
	}
}

void TitleScreen::Draw(sf::RenderWindow &Window)
{
	startBtn.render(Window);
	Window.draw(text);
}

