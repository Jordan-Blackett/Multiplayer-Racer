//
//  main.cpp
//  t01
//
//  Created by Cordry, Julien on 30/09/2016.
//  Copyright © 2016 Cordry, Julien. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "World.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Fire Race Of Death!"); //1280,1024
	window.setFramerateLimit(60);

	// World
	World world;
	world.Initialization(&window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
         
        window.clear();
		world.Update();
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
//mouse/joypad
