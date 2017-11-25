#pragma once

#include "Screen.h"

class SplashScreen : public Screen
{
public:
	SplashScreen();
	~SplashScreen();

	void LoadContent();
	void UnloadContent();
	void Update();
	void Draw(sf::RenderWindow &Window);

private:
	sf::Text text;
	sf::Font font;
};
