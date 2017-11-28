#pragma once

#include "src/Screen.h"

#include "src/Player.h"
#include "src/BotRacer.h"
#include "src/Camera.h"
#include "src/HUD.h"

#include "MessageManager.h"

#include "src/Network.h"

#include <unordered_map>

class GameScreen : public Screen
{
public:
	GameScreen();
	~GameScreen();

	void LoadContent();
	void UnloadContent();
	void Update(sf::RenderWindow &Window);
	void UIUpdate(sf::RenderWindow &Window, sf::Event &event);
	void Draw(sf::RenderWindow &Window);

private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundImage;

	// Racers
	Player player_1;
	std::vector<BotRacer*> botRacers;

	Camera camera;
	HUD hud;
	
	//std::unordered_map<std::string, RacerEntity> networkPlayers; //get from lobby

	// TCP & UDP Threads
	Network network;
	bool wasButtonPressed = false;

	// UI
	TextBox txtBox;
};

