#pragma once
#include <SFML/Graphics.hpp>
class FrameRate
{
private:
    sf::Text frameRateText;
    sf::Font font;
public:
	void Initialize();           //<- called once per App start
	void Load();                 //<- called once per App start
	void Update(float deltaTime);               //<- called once per frame
	void Draw(sf::RenderWindow& window);
};

