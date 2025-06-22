#pragma once
#include<SFML\Graphics.hpp>
class Enemy
{
private:
	sf::Texture texture;

	sf::RectangleShape boundingRectangle;

	float width = 64;
	float height = 64;

	sf::Vector2i size;
public:
	sf::Sprite sprite;

public:
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);

};

