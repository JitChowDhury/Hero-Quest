#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
	sf::Texture texture;   //texture is array of pixels
	std::vector<sf::RectangleShape> bullets;
	float  bulletSpeed = .1f;
	sf::RectangleShape boundingRectangle;

	float width = 64;
	float height = 64;

	sf::Vector2i size;

public:
	sf::Sprite  sprite;     //spirte holds texture

public:
	void Initialize();           //<- called once per App start
	void Load();                 //<- called once per App start
	void Update(Enemy &enemy);               //<- called once per frame
	void Draw(sf::RenderWindow &window);                 //<- called once per frame 
};

