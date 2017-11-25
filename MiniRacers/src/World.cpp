#include "World.h"



World::World()
{
}


World::~World()
{
}

void World::Initialization(sf::RenderWindow* window, sf::Vector2f screenDimensions)
{
	// Window
	window_ = window;

	// Textures And Sprites
	// Background
	if (!backgroundTexture.loadFromFile("Resources/background.png")) {
		//std::cout << "Could not load background image" << std::endl;
	}

	backgroundImage.setTexture(backgroundTexture);
	backgroundImage.setScale(2, 2);

	// Entities
    player_1.Initialization(sf::Vector2f(500,500));
    
	BotRacer* bot1 = new BotRacer();
	bot1->Initialization(500, 500, sf::Color::Red);
	botRacers_.push_back(bot1);


	// init enemies and add to a dict
	//

    hud_.Initialization(screenDimensions);
}

void World::Update()
{
	switch (viewState_) {
	case viewState::MainMenu:
		break;
	case viewState::Game:
		// Player Input
		player_1.PlayerInput();

		// Update World State
		player_1.UpdateEntity();

		for (auto p : botRacers_) {
			p->UpdateEntity();
		}

		// screen Bonderies - TODO: Remove Hard Coded Screen Size
		if (player_1.getPosition().x > (1024 / 2)) camera.setOffset(player_1.getPosition().x - (1024 / 2), camera.getOffset().y);
		if (player_1.getPosition().y > (768 / 2)) camera.setOffset(camera.getOffset().x, player_1.getPosition().y - (768 / 2));

        hud_.UpdateHUD();
            
		// Render
		window_->draw(backgroundImage);

		for (auto p : botRacers_)
			p->RenderEntity(*window_, camera.getOffset());

		player_1.RenderEntity(*window_, camera.getOffset());
		backgroundImage.setPosition(-camera.getOffset());
            
        hud_.RenderHUD(*window_, camera.getOffset());
		break;
	case viewState::Settings:
		break;
	case viewState::Paused:
		break;
	}
}
