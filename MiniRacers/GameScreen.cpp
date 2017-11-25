#include "GameScreen.h"



GameScreen::GameScreen()
{
}


GameScreen::~GameScreen()
{
}

void GameScreen::LoadContent()
{
	// Textures And Sprites
	// Background
	if (!backgroundTexture.loadFromFile("Resources/background.png")) {
		std::cout << "Game Screen: Could not load map background image" << std::endl;
	}

	backgroundImage.setTexture(backgroundTexture);
	backgroundImage.setScale(2, 2);

	// Entities - Start Location
	player_1.Initialization(sf::Vector2f(500, 500));

	BotRacer* bot1 = new BotRacer();
	bot1->Initialization(500, 500, sf::Color::Red);
	botRacers.push_back(bot1);

	// HUD - Set screenDimensions screenmanager->getscreenDimensions
	hud.Initialization(sf::Vector2f(500,500));
}

void GameScreen::UnloadContent()
{

}

void GameScreen::Update()
{
	// Player Input
	player_1.PlayerInput();

	// Update World State
	player_1.UpdateEntity();

	for (auto p : botRacers) {
		p->UpdateEntity();
	}

	// screen Bonderies
	if (player_1.getPosition().x > (1024 / 2)) camera.setOffset(player_1.getPosition().x - (1024 / 2), camera.getOffset().y);
	if (player_1.getPosition().y > (768 / 2)) camera.setOffset(camera.getOffset().x, player_1.getPosition().y - (768 / 2));

	hud.UpdateHUD();
}

void GameScreen::Draw(sf::RenderWindow &Window)
{
	// Render
	Window.draw(backgroundImage);

	for (auto p : botRacers)
		p->RenderEntity(Window, camera.getOffset());

	player_1.RenderEntity(Window, camera.getOffset());
	backgroundImage.setPosition(-camera.getOffset());

	hud.RenderHUD(Window, camera.getOffset());
}

