#include <iostream>
#include "Player.h"

void Player::Initialize()
{
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/Sprite_Up.png"))
    {
        std::cout << "Player Image Loaded";
        sprite.setTexture(texture);
        //Int
        int XIndex = 0;
        int YIndex = 0;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));//(X,Y,Width,Height)//select a part of the spriteSheet
        sprite.scale(sf::Vector2f(3, 3));
        sprite.setPosition(sf::Vector2f(750, 400));
    }
    else
    {
        std::cout << "Player Image Failed to Load" << std::endl;
    }
}

void Player::Update()
{
    sf::Vector2f position = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))//its on update
    {

        sprite.setPosition(position + sf::Vector2f(1, 0));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {

        sprite.setPosition(position + sf::Vector2f(-1, 0));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {

        sprite.setPosition(position + sf::Vector2f(0, -1));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {

        sprite.setPosition(position + sf::Vector2f(0, 1));
    }
}

void Player::Draw()
{
}
 