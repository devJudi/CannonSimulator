#include "MainWindow.h"

MainWindow::MainWindow(int x, int y, std::string name, int fps)
:RenderWindow(sf::VideoMode(x, y), name)
{
    this->setFramerateLimit(fps);
}

MainWindow::~MainWindow()
{
    //dtor
}


void MainWindow::handleEvent(sf::Event event, std::vector <Ball> &balls, int &numberOfBalls)
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
                sf::Window *window = this;
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                balls.push_back(Ball(30));
                balls[numberOfBalls].setPosition(sf::Vector2f(mousePos));
                numberOfBalls++;
            }
        }

}
