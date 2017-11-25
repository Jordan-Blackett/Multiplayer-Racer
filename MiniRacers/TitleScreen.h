#pragma once

#include "src/Screen.h"

class TitleScreen : public Screen
{
public:
	TitleScreen();
	~TitleScreen();

	void LoadContent();
	void UnloadContent();
	void Update(sf::Keyboard::Key key);
	void Draw(sf::RenderWindow &Window);

private:
	sf::Text text;
	sf::Font font;
};

