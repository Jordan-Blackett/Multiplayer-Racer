#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#include "Network.h"
#include "../UIManager.h"

class Screen
{
public:
	Screen();
	~Screen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(sf::RenderWindow &Window);
	virtual void UIUpdate(sf::RenderWindow &Window, sf::Event &event);
	virtual void Draw(sf::RenderWindow &Window);
protected:
	UIManager ui;
	Network network;
private:
};

