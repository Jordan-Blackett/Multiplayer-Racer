#include "HUD.h"



HUD::HUD()
{
}


HUD::~HUD()
{
}

void HUD::Initialization(sf::Vector2f screenDimensions){
    screenDimensions_ = screenDimensions;
    
    if (!minimapTexture_.loadFromFile("/Volumes/p4100732/Year 3/base 2/Resources/minimap.png")) {
        //std::cout << "Error could not load player image" << std::endl;
    }
    
    minimapSprite_.setTexture(minimapTexture_);
    minimapSprite_.setPosition(10, screenDimensions_.y - 200);
    
    
    // Text And Font
    if (!font.loadFromFile("/Volumes/p4100732/Year 3/base 2/Resources/Principality.ttf")) {}
    text.setFont(font);
    text.setString("0");
    text.setCharacterSize(54);
    //text.setColor(sf::Color::Red);
    text.setPosition(500, 500);
    
    // Timer
    textTime_.setFont(font);
    textTime_.setString("TIME!");
    textTime_.setCharacterSize(54);
    textTime_.setPosition(screenDimensions_.x - 250, 15);
    
    textTimer_.setFont(font);
    textTimer_.setString("00:00");
    textTimer_.setCharacterSize(54);
    textTimer_.setPosition(screenDimensions_.x - 250, 60);
}

void HUD::UpdateHUD()
{
    Timer();
}

void HUD::RenderHUD(sf::RenderWindow& window, sf::Vector2f cameraPosition)
{
    window.draw(minimapSprite_);
    window.draw(text);
    window.draw(textTime_);
    window.draw(textTimer_);
}

void HUD::Timer(){
    elapsed = clock.getElapsedTime();
    std::string text = "0:" + std::to_string(elapsed.asSeconds());
    textTimer_.setString(text);
}
