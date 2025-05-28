#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //--------------------------------INITIALIZE-----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game",sf::Style::Default,settings);//renderwindow class , window is object
    //sf::CircleShape shape(50.0f);
    //shape.setFillColor(sf::Color::Red);
    //shape.setPosition(sf::Vector2f(100, 100));

    
    //--------------------------------INITIALIZE-----------------------------------
    //--------------------------------LOAD-----------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/Sprite_Up.png"))
    {
        std::cout << "Player Image Loaded";
        playerSprite.setTexture(playerTexture);
        //Int
        int XIndex = 0;
        int YIndex = 0;
        playerSprite.setTextureRect(sf::IntRect(XIndex*64, YIndex*64, 64, 64));//(X,Y,Width,Height)
        playerSprite.scale(sf::Vector2f(3, 3));
    }
    else
    {
        std::cout << "Player Image Failed to Load" << std::endl;
    }
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
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::D)
                {
                  sf::Vector2f position=playerSprite.getPosition();
                  playerSprite.setPosition(position + sf::Vector2f(1, 0));

                }
            }
        }
        //--------------------------------UPDATE-----------------------------------

        //---------------------------------DRAW------------------------------------
        //{CLEAR > DRAW > SWAP BUFFER)
        window.clear(sf::Color::Black);//1.clears screen from prev 

        window.draw(playerSprite);
        window.display(); //swap the back buffer with front
        //---------------------------------DRAW------------------------------------
    }
    return 0;
} 