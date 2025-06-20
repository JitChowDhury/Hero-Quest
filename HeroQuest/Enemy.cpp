#include "Enemy.h"
#include<iostream>

void Enemy::Initialize()
{
    size = sf::Vector2i(32, 32);
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Green);
    boundingRectangle.setOutlineThickness(1);
}

void Enemy::Load()
{
    if (texture.loadFromFile("Assets/Enemy/Textures/Enemy_Idle.png"))
    {
        std::cout << "Enemy texture loaded" << std::endl;
        sprite.setTexture(texture);

        int XIndex = 0;
        int YIndex = 0;

        sprite.scale(sf::Vector2f(3, 3));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));//(X,Y,Width,Height)//select a part of the spriteSheet

        sprite.setPosition(sf::Vector2f(100, 50));

    }
}

void Enemy::Update()
{
    boundingRectangle.setPosition(sprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
}
