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

	//networkgamescreen and gamescreen
	//number of players number of bots
	player_1.Initialization(sf::Vector2f(500, 500));

	BotRacer* bot1 = new BotRacer();
	bot1->Initialization(500, 500, sf::Color::Red);
	botRacers.push_back(bot1);

	// HUD - Set screenDimensions screenmanager->getscreenDimensions
	hud.Initialization(sf::Vector2f(500,500));

	// UI
	txtBox.init(sf::Vector2i(25, 600), sf::Vector2i(100, 24), 12);
}

void GameScreen::UnloadContent()
{

}

void GameScreen::Update(sf::RenderWindow &Window)
{
	// Get pos loop though number of playersS
	//

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
	
	// DEBUG INPUT
	//bool isButtonPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::C)
	//	|| sf::Keyboard::isKeyPressed(sf::Keyboard::H)
	//	|| sf::Keyboard::isKeyPressed(sf::Keyboard::J);

	////once
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && !wasButtonPressed) {
	//	network.Init();
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && !wasButtonPressed) {
	//	network.TCP_Send("hello::<EOF>");
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && !wasButtonPressed) {
	//	network.UDP_Send("hello");
	//}

	//wasButtonPressed = isButtonPressed;
	//


}

void GameScreen::UIUpdate(sf::RenderWindow &Window, sf::Event &event)
{
	// UI

	// Buttons


	// Text Boxes
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i position = sf::Mouse::getPosition(Window);
		txtBox.IsClicked(position);
	}

	txtBox.inputText(Window, event);
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

	// UI
	txtBox.render(Window);
}

