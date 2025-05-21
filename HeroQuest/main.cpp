#include <SFML/Graphics.hpp>

int main()
{
    //--------------------------------INITIALIZE-----------------------------------
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game");//renderwindow class , window is object
    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Yellow);

    sf::RectangleShape rectangle(sf::Vector2f(120.f,50.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(200, 200);
    //--------------------------------INITIALIZE-----------------------------------
  
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
        }
        //--------------------------------UPDATE-----------------------------------

        //---------------------------------DRAW------------------------------------
        //{CLEAR > DRAW > SWAP BUFFER)
        window.clear(sf::Color::Black);//1.clears screen from prev 
        window.draw(shape);//2.draw stuff on back buffer
        window.draw(rectangle);

        window.display(); //swap the back buffer with front
        //---------------------------------DRAW------------------------------------
    }
    return 0;
} 