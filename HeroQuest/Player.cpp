#include <iostream>
#include "Player.h"
#include "Math.h"


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

void Player::Update(Enemy &enemy)
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



    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(25, 12)));
        int i = bullets.size() - 1;
        bullets[i].setFillColor(sf::Color::Red);
        bullets[i].setPosition(sprite.getPosition());

    }

    for (size_t i = 0; i < bullets.size(); i++)
    {

        sf::Vector2f bulletDirection = (enemy.sprite.getPosition() - bullets[i].getPosition());
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);


    for (auto i : bullets)
    {
        window.draw(i);
    }
}
 