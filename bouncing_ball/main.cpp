#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>

int main() {
    while (true)
    {
        int WIDTH, HEIGHT = 200;
        
        sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
        sf::CircleShape shape(15.f);
        shape.setFillColor(sf::Color::Green);
        
        float xVel = .5;
        float yVel = -.3;

        float xPos = 0;
        float yPos = 0;

         
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            shape.setPosition(xPos, yPos);

            if (xPos >= 500.f)
            {
                xVel *= -1;
                xPos = 499;
                
            }
            else if ( xPos <= 0.f)
            {
                xPos = 1;
                xVel *= -1;
            }
            

            if (yPos >= 500.f)
            {
                yVel *= -1;
                yPos = 499;
            }
            else if (yPos <= 0.f) 
            {
                yPos = 1;
                yVel *= -1;
            }

            xPos += xVel;
            yPos += yVel;

            std::cout << xPos << " - " << yPos << std::endl;
            
            sleep(.5);
            window.clear();
            window.draw(shape);
            window.display();
            
        }

    }
    

    return 0;
}