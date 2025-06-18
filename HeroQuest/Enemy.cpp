#include "Enemy.h"
#include<iostream>

void Enemy::Initialize()
{
}

void Enemy::Load()
{
    if (texture.loadFromFile("Assets/Enemy/Textures/Enemy_Idle.png"))
    {
        std::cout << "Enemy texture loaded" << std::endl;
        sprite.setTexture(texture);

        int XIndex = 0;
        int YIndex = 0;

        sprite.setTextureRect(sf::IntRect(XIndex * 32, YIndex * 32, 32, 32));
        sprite.scale(sf::Vector2f(3, 3));
        sprite.setPosition(sf::Vector2f(100, 50));

    }
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}
