#pragma once

#include "RacerEntity.h"

class Player : public RacerEntity
{
public:
	Player();
	~Player();

	void Initialization(sf::Vector2f startPosition);

	void PlayerInput();
	void UpdateEntity();
	void RenderEntity(sf::RenderWindow& window, sf::Vector2f cameraPosition);
    
private:
    sf::Texture racerOutlineTexture_;
    sf::Sprite racerOutlineSprite_;
    
    sf::Color racerColour;

};

