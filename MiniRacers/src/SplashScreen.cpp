#include "SplashScreen.h"



SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::LoadContent()
{
	if (!font.loadFromFile("Resources/Font/Games.ttf"))
		std::cout << "Splash Screen: Cound not load font" << std::endl;

	text.setFont(font);
	text.setString("Splash Screen");
}

void SplashScreen::UnloadContent()
{

}

void SplashScreen::Update()
{

}

void SplashScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
}
