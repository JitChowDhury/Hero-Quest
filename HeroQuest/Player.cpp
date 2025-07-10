#include <iostream>
#include "Player.h"
#include "Math.h"



Player::Player() :bulletSpeed(0.5f), playerSpeed(1.0f), maxFireRate(250), fireRateTimer(0)
{

}

Player::~Player()
{
    std::cout << "LOML PLAYER DED AF XD" << std::endl;
}

void Player::Initialize()
{
    size = sf::Vector2i(64 , 64);
    boundingRectangle.setFillColor(sf::Color::Transparent);//rectangle to understand the outline of player sprite
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);
     
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

        sprite.scale(sf::Vector2f(3, 3));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));//(X,Y,Width,Height)//select a part of the spriteSheet
        
        sprite.setPosition(sf::Vector2f(750, 400));
    }
    else
    {
        std::cout << "Player Image Failed to Load" << std::endl;
    }
}

void Player::Update(float deltaTime,Enemy &enemy)
{
    sf::Vector2f position = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))//its on update
    {

        sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {

        sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {

        sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {

        sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);
    }

    //----------------------------------------------------------------------------------------------------------------
    fireRateTimer += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >=maxFireRate)
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(25, 12)));
        int i = bullets.size() - 1;
        bullets[i].setFillColor(sf::Color::Red);
        bullets[i].setPosition(sprite.getPosition());

        fireRateTimer = 0;

    }

    for (size_t i = 0; i < bullets.size(); i++)
    {

        sf::Vector2f bulletDirection = (enemy.sprite.getPosition() - bullets[i].getPosition());
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);


        if (Math::checkRectCollision(bullets[i].getGlobalBounds(), enemy.sprite.getGlobalBounds()))
        {
            enemy.changeHP(-10);
            if (enemy.health <= 0) enemy.sprite.setScale(sf::Vector2f(0,0));
            bullets.erase(bullets.begin() + i);
            std::cout << "Enemy Health: " << enemy.health<< std::endl;
            
        }
    }

    boundingRectangle.setPosition(sprite.getPosition());

    //----------------------------------------------------------------------------------------------------------------z
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);


    for (auto i : bullets)
    {
        window.draw(i);
    }
}
 