#include <SFML/Graphics.hpp>
#include<iostream>

#include "Player.h"
#include "Enemy.h"
 



int main()

{
    //--------------------------------INITIALIZE-----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(900, 600), "RPG Game",sf::Style::Default,settings);//renderwindow class , window is object
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);

    //--------------------------------INITIALIZE-----------------------------------
    Player player;
    Enemy enemy;
    //--------------------------------INITIALIZE-----------------------------------
    player.Initialize();
    enemy.Initialize();
    //--------------------------------INITIALIZE-----------------------------------
    //--------------------------------LOAD-----------------------------------
    player.Load();
    enemy.Load();
    //--------------------------------LOAD-----------------------------------
    sf::Clock clock;


    while (window.isOpen())//everytime we go through we draw one frame so in o  sec it runs 60 time for 60fps
    {
        sf::Time deltaTimeTimer = clock.restart();

        float deltaTime = deltaTimeTimer.asMicroseconds();
        std::cout << "Delta Time: " << deltaTime << std::endl;


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
            }
        }

        enemy.Update(deltaTime);
        player.Update(deltaTime,enemy);


        //--------------------------------UPDATE-----------------------------------

        //---------------------------------DRAW------------------------------------
        //{CLEAR > DRAW > SWAP BUFFER)
        window.clear(sf::Color::Black);//1.clears screen from prev 
        enemy.Draw(window);
        player.Draw(window);

        
        

        window.display(); //swap the back buffer with front
        //---------------------------------DRAW------------------------------------

        clock.restart();
    }
    return 0;
} 