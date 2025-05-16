#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");//renderwindow class , window is object
  
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))//event will be saved in the var event
        {
            if (event.type == sf::Event::Closed)//checks if the type is close
            {
                window.close();
            }
        }
        window.clear(sf::Color::Red);//clears screen from prev

        window.display(); //copying the data from back buffer and draw it on screen
    }
    return 0;
} 