#include "FrameRate.h"
#include <iostream> 

FrameRate::FrameRate():timer(0)
{
    std::cout << "Object is created and value of timer is "<< timer << std::endl;

}

FrameRate::~FrameRate()
{
    std::cout << "Object is Destroyed" << std::endl;
}

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
    timer += deltaTime;
    if (timer >= 100)
    {
    float fps = 1000.0f / deltaTime;
    std::string frameRateString = "FPS: " + std::to_string((int)fps) + "   FrameTime:  " + std::to_string((int)deltaTime);
    frameRateText.setString(frameRateString);
    timer = 0;
    }

}

void FrameRate::Draw(sf::RenderWindow& window)
{
    window.draw(frameRateText);
}
