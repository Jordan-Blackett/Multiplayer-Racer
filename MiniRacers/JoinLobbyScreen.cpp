#include "JoinLobbyScreen.h"



JoinLobbyScreen::JoinLobbyScreen()
{
}


JoinLobbyScreen::~JoinLobbyScreen()
{
}

void JoinLobbyScreen::LoadContent()
{
	// UI

	// Buttons
	joinBtn.init(sf::Vector2i(400, 300), "Resources/Button/Start.png");

	// Join
	joinIpAddressTxtBox.init(sf::Vector2i(400, 400), sf::Vector2i(150, 24), 20);
	joinPortTxtBox.init(sf::Vector2i(400, 450), sf::Vector2i(150, 24), 20);
	joinUsernameTxtBox.init(sf::Vector2i(400, 500), sf::Vector2i(150, 24), 20);

}

void JoinLobbyScreen::UnloadContent()
{
}

void JoinLobbyScreen::Update(sf::RenderWindow & Window)
{
}

void JoinLobbyScreen::UIUpdate(sf::RenderWindow & Window, sf::Event & event)
{
	// UI
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// Buttons
		sf::Vector2i position = sf::Mouse::getPosition(Window);
		if (joinBtn.IsClicked(position))
		{
			// Get Strings
			// Next Screen
		}

		// Text Boxes
		joinIpAddressTxtBox.IsClicked(position);
		joinPortTxtBox.IsClicked(position);
		joinUsernameTxtBox.IsClicked(position);
	}

	joinIpAddressTxtBox.inputText(Window, event);
	joinPortTxtBox.inputText(Window, event);
	joinUsernameTxtBox.inputText(Window, event);

	//connect - foreach getstring
}

void JoinLobbyScreen::Draw(sf::RenderWindow & Window)
{
	// Buttons
	joinBtn.render(Window);

	// Text Boxes
	joinIpAddressTxtBox.render(Window);
	joinPortTxtBox.render(Window);
	joinUsernameTxtBox.render(Window);
}
