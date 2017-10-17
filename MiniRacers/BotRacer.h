#pragma once

#include "RacerEntity.h"

class BotRacer : public RacerEntity
{
public:
	BotRacer();
	~BotRacer();
	
	void Initialization(int posX, int posY, sf::Color carColor);

	void UpdateEntity();
	void RenderEntity(sf::RenderWindow& window, sf::Vector2f cameraPosition);

	void move();

private:
};

