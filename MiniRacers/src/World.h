#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "BotRacer.h"
#include "Camera.h"
#include "HUD.h"

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

	void Initialization(sf::RenderWindow* window, sf::Vector2f screenDimensions);
	void Update();

private:
	sf::RenderWindow* window_{ nullptr };

	sf::Texture backgroundTexture;
	sf::Sprite backgroundImage;

	Player player_1;
	std::vector<BotRacer*> botRacers_;

	viewState viewState_{ viewState::Game };

	Camera camera;
    HUD hud_;
    
};

