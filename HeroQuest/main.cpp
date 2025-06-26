#include <SFML/Graphics.hpp>
#include<iostream>

#include "Player.h"
#include "Enemy.h"
#include "FrameRate.h"
 



int main()

{
    //--------------------------------INITIALIZE-----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(900, 600), "RPG Game",sf::Style::Default,settings);//renderwindow class , window is object
    //window.setVerticalSyncEnabled(true);//enables vsync
    //window.setFramerateLimit(60);


    //--------------------------------INITIALIZE-----------------------------------
    Player player;
    Enemy enemy;
    FrameRate frameRate;
    
    //--------------------------------INITIALIZE-----------------------------------
    player.Initialize();
    enemy.Initialize();
    frameRate.Initialize();
    //--------------------------------INITIALIZE-----------------------------------
    //--------------------------------LOAD-----------------------------------
    player.Load();
    enemy.Load();
    frameRate.Load();

   
    //--------------------------------LOAD-----------------------------------
    sf::Clock clock;


    while (window.isOpen())//everytime we go through we draw one frame so in o  sec it runs 60 time for 60fps
    {
        sf::Time deltaTimeTimer = clock.restart();//gets the time elapesd before restarting the clock;
        double deltaTime = deltaTimeTimer.asMilliseconds();

        //std::cout << "FPS: " << int(1000/deltaTime) <<" FrameTime:"<<deltaTime<< std::endl;


        //--------------------------------UPDATE-----------------------------------
        sf::Event event;
        while (window.pollEvent(event))//event will be saved in the var event
        {
        
            if (event.type == sf::Event::Closed)//checks if the type is close
            {
                window.close();
            }
          
        }
        frameRate.Update(deltaTime);

        enemy.Update(deltaTime);
        player.Update(deltaTime,enemy);
        //--------------------------------UPDATE-----------------------------------

        //---------------------------------DRAW------------------------------------
        //{CLEAR > DRAW > SWAP BUFFER)
        window.clear(sf::Color::Black);//1.clears screen from prev 
        enemy.Draw(window);
        player.Draw(window);
        frameRate.Draw(window); 
        
       

        window.display(); //swap the back buffer with front
        //---------------------------------DRAW------------------------------------

       
    }
    return 0;
} 