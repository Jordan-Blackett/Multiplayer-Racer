#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

//#include "ScreenManager.h"
#include "../UIManager.h"

class Screen
{
public:
	Screen();
	~Screen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(sf::RenderWindow &Window);
	virtual void Draw(sf::RenderWindow &Window);
protected:
	UIManager ui;
private:
};

