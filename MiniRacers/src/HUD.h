#pragma once

#include <SFML/Graphics.hpp>

class HUD
{
public:
	HUD();
	~HUD();

    void Initialization(sf::Vector2f screenDimensions);
    
    void UpdateHUD();
    void RenderHUD(sf::RenderWindow& window, sf::Vector2f cameraPosition);
    
    void Timer();
    void MiniMap();
    
private:
	sf::Vector2f screenDimensions_;
    
    sf::Texture minimapTexture_;
    sf::Sprite minimapSprite_;

    // Text
    sf::Font font;
    sf::Text text;
    sf::Text textTime_;
    sf::Text textTimer_;
    
    // Timer
    sf::Time elapsed;
    sf::Clock clock;
    
};

