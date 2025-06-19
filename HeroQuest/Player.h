#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
	sf::Texture texture;   //texture is array of pixels
	std::vector<sf::RectangleShape> bullets;
	float  bulletSpeed = .1f;
public:
	sf::Sprite  sprite;     //spirte holds texture

public:
	void Initialize();           //<- called once per App start
	void Load();                 //<- called once per App start
	void Update(Enemy &enemy);               //<- called once per frame
	void Draw(sf::RenderWindow &window);                 //<- called once per frame 
};

