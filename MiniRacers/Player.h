#pragma once

#include "RacerEntity.h"

class Player : public RacerEntity
{
public:
	Player();
	~Player();

	void Initialization();

	void PlayerInput();
	void UpdateEntity();
	void RenderEntity(sf::RenderWindow& window, sf::Vector2f cameraPosition);

};

