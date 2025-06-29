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

// Updates the frame rate display based on the time passed since the last frame
void FrameRate::Update(float deltaTime)
{
    // Add the time since the last frame to the timer
    timer += deltaTime;

    // Only update the FPS display every 100 milliseconds (or however your time unit is interpreted)
    if (timer >= 100)
    {
        // Calculate FPS as 1000 divided by deltaTime (assuming deltaTime is in milliseconds)
        float fps = 1000.0f / deltaTime;

        // Create a string showing the FPS and the frame time
        std::string frameRateString = "FPS: " + std::to_string((int)fps) + "   FrameTime:  " + std::to_string((int)deltaTime);

        // Set the text object to display the FPS and frame time
        frameRateText.setString(frameRateString);

        // Reset the timer to start counting again for the next update
        timer = 0;
    }
}

void FrameRate::Draw(sf::RenderWindow& window)
{
    window.draw(frameRateText);
}
