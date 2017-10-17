#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera();
	~Camera();

	void setPosition(int posX, int posY) {}
	sf::Vector2f getPosition() { return position_; }

	void setOffset(int offsetX, int offsetY) { offset.x = offsetX; offset.y = offsetY; }
	sf::Vector2f getOffset() { return offset; }

private:
	sf::Vector2f position_;
	sf::Vector2f offset;
};

