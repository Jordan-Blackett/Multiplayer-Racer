#include "BotRacer.h"



BotRacer::BotRacer()
{
}


BotRacer::~BotRacer()
{
}

void BotRacer::Initialization(int posX, int posY, sf::Color carColor)
{
	if (!racerTexture_.loadFromFile("/Volumes/p4100732/Year 3/base 2/Resources/car.png")) {
        std::cout << "Error could not load player image" << std::endl;
	}

	racerSprite_.setTexture(racerTexture_);
	racerSprite_.setOrigin((racerTexture_.getSize().x / 2), (racerTexture_.getSize().y / 2));
	racerSprite_.setColor(carColor);

	position_.x = posX;
	position_.y = posY;
	speed_ = 2;
	angle_ = 2;
}

void BotRacer::UpdateEntity() {
	move();
}

void BotRacer::RenderEntity(sf::RenderWindow& window, sf::Vector2f cameraPosition)
{
	racerSprite_.setPosition(position_ - cameraPosition);
	racerSprite_.setRotation(angle_ * 180 / 3.141592);
	//racerSprite_.setColor(Color::Red);

	window.draw(racerSprite_);
}

void BotRacer::move() 
{
    position_.x += sin(angle_) * speed_;
	position_.y -= cos(angle_) * speed_;
}
