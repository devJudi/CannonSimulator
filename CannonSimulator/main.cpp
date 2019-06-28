#include <iostream>
#include <vector>
#include "MainWindow.h"
#include "Ball.h"

int main()
{
    MainWindow window(800, 600, "Cannon simulator v0.0");
    std::vector <Ball> balls;
    int numberOfBalls = 0;

    while(window.isOpen())
    {
        sf::Event event;
        window.handleEvent(event, balls, numberOfBalls);

        window.clear();
        for(int i = 0; i<numberOfBalls; i++)
        {
            balls[i].doGravity(window.getSize().y);
            window.draw(balls[i]);
        }
        window.display();
    }

    return 0;
}
