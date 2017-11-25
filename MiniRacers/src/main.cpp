//
//  main.cpp
//  t01
//
//  Created by Cordry, Julien on 30/09/2016.
//  Copyright © 2016 Cordry, Julien. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include "World.h"

#include "Network.h"

int main()
{
    sf::Vector2f screenDimensions(1024, 768);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Fire Race Of Death!"); //1280,1024
	window.setFramerateLimit(60);

	// ScreenManager
	ScreenManager::GetInstance()->SetText("hello");
	ScreenManager::GetInstance()->DrawText();
	//

	ScreenManager::GetInstance()->Initialize();
	ScreenManager::GetInstance()->LoadContent();


	// World
	//World world;
	//world.Initialization(&window, screenDimensions);
                         
    // TCP & UDP Threads
    Network network;
    bool wasButtonPressed = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

			if (event.key.code == sf::Keyboard::S)
				ScreenManager::GetInstance()->AddScreen(new GameScreen);
        }
        //
        // DEBUG INPUT
        bool isButtonPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::C)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::H)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::J);
        
        //once
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && !wasButtonPressed) {
            network.Init();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && !wasButtonPressed) {
            network.TCP_Send("hello::<EOF>");
        }

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && !wasButtonPressed) {
			network.UDP_Send("hello");
		}
        
        wasButtonPressed = isButtonPressed;
        //
		
		ScreenManager::GetInstance()->Update();

        window.clear();
		ScreenManager::GetInstance()->Draw(window);
        window.display();
    }

    return 0;
}

//-game Logic
//-Render
//fake position - map position
//team colours
//teamed/freemode
//arrows pointing where next turn
//health/damage/ repair












//mouse/joypad http://www.lucidarme.me/?p=6169
