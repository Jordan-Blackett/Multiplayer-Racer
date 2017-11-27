#pragma once

#include "src/Screen.h"

class TitleScreen : public Screen
{
public:
	TitleScreen();
	~TitleScreen();

	void LoadContent();
	void UnloadContent();
	void Update(sf::RenderWindow &Window);
	void Draw(sf::RenderWindow &Window);

private:
	sf::Text text;
	sf::Font font;

	//Buttons
	Button startBtn;
};

