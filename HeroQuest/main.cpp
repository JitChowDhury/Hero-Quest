#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //--------------------------------INITIALIZE-----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(900, 600), "RPG Game",sf::Style::Default,settings);//renderwindow class , window is object
    //sf::CircleShape shape(50.0f);
    //shape.setFillColor(sf::Color::Red);
    //shape.setPosition(sf::Vector2f(100, 100));

    
    //--------------------------------INITIALIZE-----------------------------------
    sf::RectangleShape bullet(sf::Vector2f(25, 12));
    bullet.setPosition(sf::Vector2f(700, 400));
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
        
    }
    
    //--------------------------------ENEMY----------------------------------- 
    //--------------------------------PLAYER----------------------------------- 
    
    sf::Texture playerTexture;//texture is array of pixels
    sf::Sprite playerSprite;//spirte holds texture

    if (playerTexture.loadFromFile("Assets/Player/Textures/Sprite_Up.png"))
    {
        std::cout << "Player Image Loaded";
        playerSprite.setTexture(playerTexture);
        //Int
        int XIndex = 0;
        int YIndex = 0;
        playerSprite.setTextureRect(sf::IntRect(XIndex*64, YIndex*64, 64, 64));//(X,Y,Width,Height)//select a part of the spriteSheet
        playerSprite.scale(sf::Vector2f(3, 3));
        playerSprite.setPosition(sf::Vector2f(750, 400));
    }
    else
    {
        std::cout << "Player Image Failed to Load" << std::endl;
    }
    //--------------------------------PLAYER----------------------------------- 
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
                if (event.key.code == sf::Keyboard::F)
                {
                  sf::Vector2f position=playerSprite.getPosition();
                  playerSprite.setPosition(position + sf::Vector2f(10, 0));

                }
            }
         
        }
        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))//its on update
        {
            
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
           
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }
        //--------------------------------UPDATE-----------------------------------

        //---------------------------------DRAW------------------------------------
        //{CLEAR > DRAW > SWAP BUFFER)
        window.clear(sf::Color::Black);//1.clears screen from prev 

        window.draw(playerSprite);
        window.draw(enemySprite);
        window.draw(bullet);
        window.display(); //swap the back buffer with front
        //---------------------------------DRAW------------------------------------
    }
    return 0;
} 