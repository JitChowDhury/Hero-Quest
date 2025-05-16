#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");//renderwindow class , window is object
  
    while (window.isOpen())
    {
        //--------------------------------UPDATE-----------------------------------
        sf::Event event;
        while (window.pollEvent(event))//event will be saved in the var event
        {
            if (event.type == sf::Event::Closed)//checks if the type is close
            {
                window.close();
            }
        }
        //--------------------------------UPDATE-----------------------------------

        //---------------------------------DRAW------------------------------------
        window.clear(sf::Color::Red);//1.clears screen from prev
        //2.draw stuff on back buffer

        window.display(); //copying the data from back buffer and draw it on screen
        //---------------------------------DRAW------------------------------------
    }
    return 0;
} 