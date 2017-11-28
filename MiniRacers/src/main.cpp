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
	ScreenManager::GetInstance()->Initialize();
	ScreenManager::GetInstance()->LoadContent();               
	std::string s;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

			if (event.key.code == sf::Keyboard::P)
				ScreenManager::GetInstance()->AddScreen(new GameScreen);

			ScreenManager::GetInstance()->UIUpdate(window, event);
        }
		
		// Update World
		ScreenManager::GetInstance()->Update(window);

		// Render World
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
