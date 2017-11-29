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
	joinBtn.init(sf::Vector2i((ScreenWidth / 2), 300), "Resources/Button/Start.png");
	backBtn.init(sf::Vector2i((ScreenWidth / 2), 600), "Resources/Button/Start.png");

	// Join
	joinIpAddressTxtBox.init(sf::Vector2i(400, 400), sf::Vector2i(150, 24), "192.168.0.10", 20);
	joinPortTxtBox.init(sf::Vector2i(400, 450), sf::Vector2i(150, 24), "8080", 20);
	joinUsernameTxtBox.init(sf::Vector2i(400, 500), sf::Vector2i(150, 24), "Player", 20);

	// Text
	joinIpAddressTxt.init(sf::Vector2i(375, 400), sf::Vector2i(150, 24), "IP:", 20);
	joinPortTxt.init(sf::Vector2i(340, 450), sf::Vector2i(150, 24), "Port:", 20);
	joinUsernameTxt.init(sf::Vector2i(335, 500), sf::Vector2i(150, 24), "Name:", 20);

	// PopUp
	joinIpAddressPopUp.init(sf::Vector2i(400, 100), sf::Vector2i(100, 100), 20);
}

void JoinLobbyScreen::UnloadContent()
{
}

void JoinLobbyScreen::Update(sf::RenderWindow & Window)
{
}

void JoinLobbyScreen::UIUpdate(sf::RenderWindow & Window, sf::Event & event)
{
	if (connecting)
	{
		network.Init();
		std::string status = network.GetStatus();
		if (status == "Connected")
		{
			joinIpAddressPopUp.setText(network.GetStatus());
			connecting = false;
			//ScreenManager::GetInstance()->AddScreen(new GameScreen);
			
		}
		if (status == "Connection Failed")
		{
			joinIpAddressPopUp.setText(network.GetStatus());
			connecting = false;
		}
	}
	else {
		// UI
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// Buttons
			sf::Vector2i position = sf::Mouse::getPosition(Window);
			if (joinBtn.IsClicked(position))
			{
				joinIpAddressPopUp.setText("Connecting...");
				joinIpAddressPopUp.setActive(true);

				std::cout << joinIpAddressTxtBox.GetText() << std::endl;
				network.SetIPAddress(joinIpAddressTxtBox.GetText());
				network.SetTCPPort(joinPortTxtBox.GetText());
				network.SetLocalUsername(joinUsernameTxtBox.GetText());
			
				connecting = true;
			}
			if (backBtn.IsClicked(position))
			{
				//ScreenManager::GetInstance()->AddScreen(new TitleScreen);
				network.TCP_Send("hello::<EOF>");
			}

			// Text Boxes
			joinIpAddressTxtBox.IsClicked(position);
			joinPortTxtBox.IsClicked(position);
			joinUsernameTxtBox.IsClicked(position);
		}

		joinIpAddressTxtBox.inputText(Window, event);
		joinPortTxtBox.inputText(Window, event);
		joinUsernameTxtBox.inputText(Window, event);
	}
}

void JoinLobbyScreen::Draw(sf::RenderWindow & Window)
{
	// Buttons
	joinBtn.render(Window);
	backBtn.render(Window);

	// Text Boxes
	joinIpAddressTxtBox.render(Window);
	joinPortTxtBox.render(Window);
	joinUsernameTxtBox.render(Window);

	//Text 
	joinIpAddressTxt.render(Window);
	joinPortTxt.render(Window);
	joinUsernameTxt.render(Window);

	joinIpAddressPopUp.render(Window);
}

