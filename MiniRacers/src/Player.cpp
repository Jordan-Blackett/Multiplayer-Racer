#include "Player.h"



Player::Player()
{
	//Initialization();
}


Player::~Player()
{
}

void Player::Initialization(sf::Vector2f startPosition)
{
	if (!racerTexture_.loadFromFile("Resources/car.png")) {
		std::cout << "Error could not load player image" << std::endl;
	}

	if (!racerOutlineTexture_.loadFromFile("Resources/car_ring.png")) {
		std::cout << "Could not load Outline image" << std::endl;
	}

	racerSprite_.setTexture(racerTexture_);
    racerOutlineSprite_.setTexture(racerOutlineTexture_);

	racerSprite_.setOrigin((racerTexture_.getSize().x / 2), (racerTexture_.getSize().y / 2));
    
    racerOutlineSprite_.setOrigin((racerOutlineTexture_.getSize().x / 2), (racerOutlineTexture_.getSize().y / 2));
    
    position_ = startPosition;
    
    //racerColour = colour;
    //racerSprite_.setColor(racerColour);
}

void Player::PlayerInput()
{
	bool Up = 0, Right = 0, Down = 0, Left = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) Up = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) Down = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) Left = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) Right = 1;

	if (Up && speed_ < maxSpeed_) {
		if (speed_ < 0) 
			speed_ += dec_;
		else 
			speed_ += acc_;
	}

	if (Down && speed_ > -maxSpeed_) {
		if (speed_ > 0)
			speed_ -= dec_;
		else
			speed_ -= acc_;
	}

	if (!Up && !Down) {
		if (speed_ - dec_ > 0) speed_ -= dec_;
		else if (speed_ + dec_ < 0) speed_ += dec_;
		else speed_ = 0;
	}
	
	if (Right && speed_ != 0) angle_ += turnSpeed_ * speed_ / maxSpeed_;
	if (Left && speed_ != 0) angle_ -= turnSpeed_ * speed_ / maxSpeed_;
}

void Player::UpdateEntity()
{
    position_.x += sin(angle_) * speed_;
    position_.y -= cos(angle_) * speed_;
}

void Player::RenderEntity(sf::RenderWindow& window, sf::Vector2f cameraPosition)
{
	racerSprite_.setPosition(position_ - cameraPosition);
	racerSprite_.setRotation(angle_ * 180 / 3.141592);

    racerOutlineSprite_.setPosition(position_ - cameraPosition);
    
	window.draw(racerSprite_);
	//window.draw(racerOutlineSprite_);
}

