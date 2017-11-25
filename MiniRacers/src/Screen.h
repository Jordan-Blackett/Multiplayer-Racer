#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Screen
{
public:
	Screen();
	~Screen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update();
	virtual void Draw(sf::RenderWindow &Window);
protected:
private:

};

