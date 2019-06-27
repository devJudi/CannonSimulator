#include <iostream>
#include <vector>
#include "MainWindow.h"
#include "Ball.h"

int main()
{
    MainWindow window(800, 600, "Cannon simulator v0.0");

    while(window.isOpen())
    {
        sf::Event event;
        window.handleEvent(event);

        window.clear();
        window.display();
    }

    return 0;
}
