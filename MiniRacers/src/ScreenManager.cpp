#include "ScreenManager.h"


// Global static pointer used to ensure a single instance of the class.
//ScreenManager* ScreenManager::instance2 = NULL;

/** This function is called to create an instance of the class.
Calling the constructor publicly is not allowed. The constructor
is private and is only called by this Instance function.
*/

// Singleton
ScreenManager* ScreenManager::GetInstance()
{
	//if (!instance2)   // Only allow one instance of class to be generated.
		//instance2 = new ScreenManager;

	static ScreenManager instance;
	return &instance;
}

ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
}

void ScreenManager::Initialize()
{
	currentScreen = new TitleScreen();
}

void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
}

void ScreenManager::Update()
{
	currentScreen->Update();
}

void ScreenManager::Draw(sf::RenderWindow &Window)
{
	currentScreen->Draw(Window);
}

void ScreenManager::SetText(std::string text)
{
	this->text = text;
}

void ScreenManager::DrawText()
{
	std::cout << text << std::endl;
}

void ScreenManager::AddScreen(Screen *screen)
{
	currentScreen->UnloadContent();
	delete currentScreen;
	currentScreen = screen;
	currentScreen->LoadContent();
}
