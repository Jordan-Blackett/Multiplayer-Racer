#pragma once

#include "src/Screen.h"
#include "src/ScreenManager.h"

class JoinLobbyScreen : public Screen
{
public:
	JoinLobbyScreen();
	~JoinLobbyScreen();

	void LoadContent();
	void UnloadContent();
	void Update(sf::RenderWindow &Window);
	void UIUpdate(sf::RenderWindow &Window, sf::Event &event);
	void Draw(sf::RenderWindow &Window);

private:

	// UI
	Button hostBtn;
	Button joinBtn;
	Button backBtn;

	// Host
	TextBox hostIpAddress;

	// Join
	Text joinIpAddressTxt;
	Text joinPortTxt;
	Text joinUsernameTxt;
	TextBox joinIpAddressTxtBox;
	TextBox joinPortTxtBox;
	TextBox joinUsernameTxtBox;

	PopUpBox joinIpAddressPopUp;

	bool popUpActive{ false };
	bool connecting{ false };

};

