//
//  main.cpp
//  t01
//
//  Created by Cordry, Julien on 30/09/2016.
//  Copyright © 2016 Cordry, Julien. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "World.h"

#include "Network.h"

int main()
{
	// Window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Fire Race Of Death!"); //1280,1024
	window.setFramerateLimit(60);

	// Game World
	World world;
	world.Initialization(&window);

	// TCP & UDP Threads
	Network network;
	bool wasButtonPressed = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
         
		//
		// DEBUG INPUT
		bool isButtonPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::C)
							|| sf::Keyboard::isKeyPressed(sf::Keyboard::H);

		//once
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && !wasButtonPressed) {
			network.Init();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && !wasButtonPressed) {
			network.TCP_Send("hello");
		}

		wasButtonPressed = isButtonPressed;
		//

        window.clear();
		world.Update();
        window.display();
    }

	//if (network.getConnected()) {
	//	network.Disconnect();
	//}

    return 0;
}



















//-game Logic
//-Render
//fake position - map position
//team colours
//teamed/freemode
//arrows pointing where next turn
//health/damage/ repair
//mouse/joypad
