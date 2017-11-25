#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class RacerEntity
{
public:
	RacerEntity();
	~RacerEntity();

	virtual void RenderEntity(sf::RenderWindow& window, sf::Vector2f cameraPosition) = 0;
	virtual void UpdateEntity() = 0;

	sf::Vector2f getPosition() { return position_; }

protected:
	sf::Texture racerTexture_;
	sf::Sprite racerSprite_;

	sf::Vector2f position_;

	// Entity Stats
	float speed_{ 0 };
	float maxSpeed_{ 6.0f };
	float angle_{ 0 };
	float acc_{ 0.1f };
	float dec_{ 0.2f };
	float turnSpeed_{ 0.04f };
};

