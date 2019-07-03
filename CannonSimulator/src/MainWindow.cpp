#include "MainWindow.h"

MainWindow::MainWindow(int x, int y, std::string name, int fps)
    :RenderWindow(sf::VideoMode(x, y), name)
{
    view.setSize(1200, 800);
    view.setCenter(600, 400);
    this->setView(view);
    this->setFramerateLimit(fps);
    shouldWatchBack=false;
}

MainWindow::~MainWindow()
{
    //dtor
}

void MainWindow::handleEvent(sf::Event event, std::vector <Ball> &balls, int &numberOfBalls, materials &materialType)
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
            else if(event.key.code==sf::Keyboard::Num1)
            {
                materialType = wooden;
            }
            else if(event.key.code==sf::Keyboard::Num2)
            {
                materialType = rubber;
            }
            else if(event.key.code==sf::Keyboard::Num3)
            {
                materialType = metal;
            }
            else if(event.key.code==sf::Keyboard::Num4)
            {
                materialType = aether;
            }
            else if(event.key.code==sf::Keyboard::Num5)
            {
                materialType = pulsar;
            }
            else if(event.key.code==sf::Keyboard::P)
            {
                cannonPower+=100;
            }
            else if(event.key.code==sf::Keyboard::O)
            {
                if(cannonPower>100)
                    cannonPower-=100;
            }
            else if(event.key.code==sf::Keyboard::L||event.key.code==sf::Keyboard::Right)
            {
                cannonPower+=1000;
            }
            else if(event.key.code==sf::Keyboard::K||event.key.code==sf::Keyboard::Left)
            {
                if(cannonPower>1000)
                    cannonPower-=1000;
            }
            else if(event.key.code==sf::Keyboard::Backspace)
            {
                if(shouldWatchBack) shouldWatchBack=false;
                else shouldWatchBack=true;
            }
            else if(event.key.code==sf::Keyboard::Up)
            {
                if(cannonAngle<89) cannonAngle++;
            }
            else if(event.key.code==sf::Keyboard::Down)
            {
                if(cannonAngle>1) cannonAngle--;
            }
        }
        if(event.type==sf::Event::MouseButtonPressed)
        {
            soundCannonFire.setVolume(cannonPower/500);
            soundCannonFire.play();
            shouldCannonFireBeVisible=true;
            balls.push_back(Ball(30, materialType));
            balls[numberOfBalls].setPosition(140, 650);
            balls[numberOfBalls].speedY=-(cannonAngle/90)*(sqrt(2*cannonPower/balls[numberOfBalls].weight));
            balls[numberOfBalls].speedX=(1-(cannonAngle/90))*(sqrt(2*cannonPower/balls[numberOfBalls].weight));
            numberOfBalls++;
        }
        else
        {
            shouldCannonFireBeVisible=false;
        }
    }

    if(shouldWatchBack==false)
    {
        if(numberOfBalls>0)
        {
            view.setCenter(balls[numberOfBalls-1].getPosition().x, 400);
            if(view.getCenter().x<600)
            {
                view.setCenter(600, 400);
            }
            if(balls[numberOfBalls-1].speedX<1)
            {
                view.setCenter(600, 400);
            }
            this->setView(view);
        }
    }
    else
    {
        view.setCenter(600, 400);
        this->setView(view);
    }

}
