#pragma once

#include <iostream>
#include <string>

#include "Screen.h"

#include "SplashScreen.h"
#include "../TitleScreen.h"
#include "../GameScreen.h"

class ScreenManager
{
public:
	~ScreenManager(); 
	static ScreenManager* GetInstance(); // Static access method.

	void SetText(std::string text);
	void DrawText();

	void Initialize();
	void LoadContent();
	void Update();
	void Draw(sf::RenderWindow &Window);

	void AddScreen(Screen *screen);

private:
	ScreenManager(); // Private constructor to prevent instancing
	ScreenManager(ScreenManager const&) {}; // = delete; // Copy constructor is private
	ScreenManager& operator=(ScreenManager const&) {}; // = delete; // Assignment operator is private

	static ScreenManager* instance;

	std::string text;

	//
	//sf::Vector2f screenDimensions(1024, 768);
	Screen *currentScreen, *newScreen;


};

