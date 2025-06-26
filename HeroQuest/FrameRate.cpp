#include "FrameRate.h"
#include <iostream> 

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
    if (font.loadFromFile("Assets/Fonts/arial.ttf"))
    {
        std::cout << "WOOOOOOO LOADED!!!" << std::endl;
        frameRateText.setFont(font);

    }
    else
    {
        std::cout << "FAILED SUCCESFULLY DUMBASS" << std::endl;
    }
}

void FrameRate::Update(float deltaTime)
{
    float fps = 1000.0f / deltaTime;

    std::string frameRateString = "FPS: " + std::to_string((int)fps) + "   FrameTime:  " + std::to_string(deltaTime);
    frameRateText.setString(frameRateString);
}

void FrameRate::Draw(sf::RenderWindow& window)
{
    window.draw(frameRateText);
}
