#include "Enemy.h"
#include<iostream>

Enemy::Enemy():health(100)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
    size = sf::Vector2i(32, 32);
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Green);
    boundingRectangle.setOutlineThickness(1);
}

void Enemy::Load()
{
    if (font.loadFromFile("Assets/Fonts/arial.ttf"))
    {
        std::cout << "WOOOOOOO LOADED!!!" << std::endl;
        healthText.setFont(font);
        healthText.setString(std::to_string(health));//health text to health
        healthText.setFillColor(sf::Color::Green);

    }
    else
    {
        std::cout << "FAILED SUCCESFULLY DUMBASS" << std::endl;
    }

    if (texture.loadFromFile("Assets/Enemy/Textures/Enemy_Idle.png"))
    {
        std::cout << "Enemy texture loaded" << std::endl;
        sprite.setTexture(texture);//assigns the texture to sprite

        int XIndex = 0;
        int YIndex = 0;

        sprite.scale(sf::Vector2f(3, 3));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));//(X,Y,Width,Height)//select a part of the spriteSheet

        sprite.setPosition(sf::Vector2f(100, 50));


    }
}


void Enemy::Update(float deltaTime)
{
    boundingRectangle.setPosition(sprite.getPosition());
    healthText.setPosition(sprite.getPosition() + sf::Vector2f(10, -30));
    
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
    window.draw(healthText);
}

void Enemy::changeHP(int HP)
{
    health += HP;
    healthText.setString(std::to_string(health));
}
