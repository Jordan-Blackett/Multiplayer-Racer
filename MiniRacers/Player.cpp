#include "Player.h"



Player::Player()
{
	Initialization();
}


Player::~Player()
{
}

void Player::Initialization()
{
	if (!racerTexture_.loadFromFile("Resources/car.png")) {
	//	std::cout << "Error could not load player image" << std::endl;
	}

	//if (!arrowTexture_.loadFromFile("Resources/img/Arrow.png")) {
	//	std::cout << "Could not load Arrow image" << std::endl;
	//}

	//if (!indicatorTexture_.loadFromFile("Resources/img/Question_Mark.png")) {
	//	std::cout << "Error could not load indicator image" << std::endl;
	//}

	racerSprite_.setTexture(racerTexture_);
	//arrowSprite_.setTexture(arrowTexture_);
	//indicatorSprite_.setTexture(indicatorTexture_);
	position_.x = 500;
	position_.y = 500;

	racerSprite_.setOrigin((racerTexture_.getSize().x / 2), (racerTexture_.getSize().y / 2));
	//arrowSprite_.setOrigin(16 / 2, 16 / 2);

	//// Text And Font
	//if (!font.loadFromFile("Resources/arial.ttf")) {}
	//text.setFont(font);
	//text.setString("0");
	//text.setCharacterSize(24);
	//text.setColor(sf::Color::Red);
	//text.setPosition(200, 200);

	////bag
	//if (!bag_.inventoryTexture.loadFromFile("Resources/img/Inventory.png")) {}
	//bag_.inventorySprite.setTexture(bag_.inventoryTexture);

	//Weapon7* weapon = new Weapon7();
	//bag_.inventory.push_back(weapon);

	//Weapon7* weapon1 = new Weapon7();
	//bag_.inventory.push_back(weapon);

	//Weapon7* weapon2 = new Weapon7();
	//bag_.inventory.push_back(weapon);
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

	position_.x += sin(angle_) * speed_;
	position_.y -= cos(angle_) * speed_;


	//racerSprite_.setPosition(position_);
	//racerSprite_.setRotation(angle_ * 180 / 3.141592);
}

void Player::UpdateEntity()
{
}

void Player::RenderEntity(sf::RenderWindow& window, sf::Vector2f cameraPosition)
{
	////	frameCounter_ = (updateFrame_) ? frameCounter_ + frameSpeed_ * clock_.restart().asSeconds() : 0;
	////
	////	if (frameCounter_ >= switchFrame_)
	////	{
	////		frameCounter_ = 0;
	////		source_.x++;
	////		if (source_.x * 34 >= 34 * 6)
	////			source_.x = 0;
	////	}
	////
	////	playerImage_.setTextureRect(sf::IntRect(source_.x * 34, source_.y * 65, flip_ * 34, 65));

	//// Arrow Position
	//sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	//float dx = position_.x + (64 / 2) - mousePosition.x;
	//float dy = position_.y + (64 / 2) - mousePosition.y;

	//int radius = 64 / 2;
	//float angle = atan2(-dy, -dx);
	//float x = radius * cos(angle);
	//float y = radius * sin(angle);
	//arrowSprite_.setPosition(x + position_.x + (64 / 2), y + position_.y + (64 / 2));

	//// Arrow Roation
	//const float PI = 3.14159265;
	//float rotation = (angle) * 180 / PI;
	//arrowSprite_.setRotation(rotation + 90);

	//if (closeToEntity_ && !rockPaperScissors_) {
	//	indicatorSprite_.setPosition(position_.x, position_.y - 25);
	//	window.draw(indicatorSprite_);
	//}

	racerSprite_.setPosition(position_ - cameraPosition);
	racerSprite_.setRotation(angle_ * 180 / 3.141592);
	racerSprite_.setColor(sf::Color::Blue);

	window.draw(racerSprite_);
	//window.draw(arrowSprite_);

	//// Inventory
	////if(bag_.isOpen == true){
	////	window.draw(bag_.inventorySprite);
	////	//tempX;
	////	//tempY;
	////	for(int i; i < bag_.inventory.size; i++) {
	////		std::string f_str = std::to_string(bag_.inventory[i]->type);
	////		text.setString("t: " + f_str);
	////		text.setPosition(0, 0);
	////		window.draw(text);
	////	}
	////}
}

