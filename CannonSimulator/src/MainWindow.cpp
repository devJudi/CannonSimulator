#include "MainWindow.h"

int numberOfBalls;

MainWindow::MainWindow(int x, int y, std::string name, int fps)
:RenderWindow(sf::VideoMode(x, y), name)
{
    this->setFramerateLimit(fps);
}

MainWindow::~MainWindow()
{
    //dtor
}


void MainWindow::handleEvent(sf::Event event)
{
    while(this->pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                this->close();
            }
            if(event.type==sf::Event::KeyPressed)
            {
                if(event.key.code==sf::Keyboard::Escape)
                {
                    this->close();
                }
            }
            if(event.type==sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition();
            }
        }

}
