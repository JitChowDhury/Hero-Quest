#include <SFML/Graphics.hpp>
#include <iostream>
#include<math.h>
#include "Player.h"


sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
  float magnitude=std::sqrt(vector.x * vector.x + vector.y * vector.y);
  sf::Vector2f normalizedVector;
  normalizedVector.x = vector.x / magnitude;
  normalizedVector.y = vector.y / magnitude;

  return normalizedVector;
   
}
                 

  

int main()
{
    //--------------------------------INITIALIZE-----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(900, 600), "RPG Game",sf::Style::Default,settings);//renderwindow class , window is object

    Player player;
    player.Initialize();
    player.Load();
    //--------------------------------INITIALIZE-----------------------------------
    std::vector<sf::RectangleShape> bullets;
   
    float  bulletSpeed = .1f;
    

    //--------------------------------LOAD-----------------------------------
    //--------------------------------ENEMY-----------------------------------
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;

    if (enemyTexture.loadFromFile("Assets/Enemy/Textures/Enemy_Idle.png"))
    {
        std::cout << "Enemy texture loaded" << std:: endl;
        enemySprite.setTexture(enemyTexture);

        int XIndex = 0;
        int YIndex = 0;

        enemySprite.setTextureRect(sf::IntRect(XIndex * 32, YIndex * 32, 32, 32));
        enemySprite.scale(sf::Vector2f(3, 3));
        enemySprite.setPosition(sf::Vector2f(100, 50));
        
    }
    
    //--------------------------------ENEMY----------------------------------- 

    //--------------------------------LOAD-----------------------------------


    while (window.isOpen())//everytime we go through we draw one frame so in o  sec it runs 60 time for 60fps
    {
        //--------------------------------UPDATE-----------------------------------
        sf::Event event;
        while (window.pollEvent(event))//event will be saved in the var event
        {
        
            if (event.type == sf::Event::Closed)//checks if the type is close
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)//it depends on poll rate ( like how often does windows check event queue)
            {
                //if (event.key.code == sf::Keyboard::F)
                //{
                //  sf::Vector2f position=playerSprite.getPosition();
                //  playerSprite.setPosition(position + sf::Vector2f(10, 0));

                //}
            }
         
        }

        player.Update();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(25, 12)));
            int i = bullets.size() - 1;
            bullets[i].setFillColor(sf::Color::Red);
            bullets[i].setPosition(player.sprite.getPosition());
             

        }


        for (size_t i = 0; i < bullets.size(); i++)
        {

            sf::Vector2f bulletDirection = (enemySprite.getPosition() - bullets[i].getPosition());
            bulletDirection = NormalizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection*bulletSpeed);
        }

        //--------------------------------UPDATE-----------------------------------

        //---------------------------------DRAW------------------------------------
        //{CLEAR > DRAW > SWAP BUFFER)
        window.clear(sf::Color::Black);//1.clears screen from prev 
        player.Draw();
        window.draw(player.sprite);
        window.draw(enemySprite);

        for(auto i :bullets)
        {
            window.draw(i);
        }
        window.display(); //swap the back buffer with front
        //---------------------------------DRAW------------------------------------
    }
    return 0;
} 