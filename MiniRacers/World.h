#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "BotRacer.h"
#include "Camera.h"

enum class viewState
{
	MainMenu,
	Game,
	Settings,
	Paused
};

class World
{
public:
	World();
	~World();

	void Initialization(sf::RenderWindow* window);
	void Update();

private:
	sf::RenderWindow* window_{ nullptr };

	sf::Texture backgroundTexture;
	sf::Sprite backgroundImage;

	Player player_1;
	std::vector<BotRacer*> botRacers_;

	viewState viewState_{ viewState::Game };

	Camera camera;
};

