#include "World.h"



World::World()
{
}


World::~World()
{
}

void World::Initialization(sf::RenderWindow* window)
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
	// Player
	//Player* player_1 = new Player();
	//player_1 = 
	//entities_.push_back(player_1);

	BotRacer* bot1 = new BotRacer();
	bot1->Initialization(100, 500, sf::Color::Red);
	botRacers_.push_back(bot1);

	// Text And Font
	//if (!font.loadFromFile("Resources/arial.ttf")) {}
	//text.setFont(font);
	//text.setString("0");
	//text.setCharacterSize(24);
	//text.setColor(sf::Color::Red);
	//text.setPosition(100, 100);
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

		// screen Bonderies
		if (player_1.getPosition().x > (1024 / 2)) camera.setOffset(player_1.getPosition().x - (1024 / 2), camera.getOffset().y);
		if (player_1.getPosition().y > (768 / 2)) camera.setOffset(camera.getOffset().x, player_1.getPosition().y - (768 / 2));

		// Render
		window_->draw(backgroundImage);

		for (auto p : botRacers_)
			p->RenderEntity(*window_, camera.getOffset());

		player_1.RenderEntity(*window_, camera.getOffset());
		backgroundImage.setPosition(-camera.getOffset());
		break;
	case viewState::Settings:
		break;
	case viewState::Paused:
		break;
	}
}