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
                cannonPower+=1;
            }
            else if(event.key.code==sf::Keyboard::O)
            {
                if(cannonPower>1)
                    cannonPower-=1;
            }
            else if(event.key.code==sf::Keyboard::L||event.key.code==sf::Keyboard::Right)
            {
                cannonPower+=10;
            }
            else if(event.key.code==sf::Keyboard::K||event.key.code==sf::Keyboard::Left)
            {
                if(cannonPower>10)
                    cannonPower-=10;
            }
            else if(event.key.code==sf::Keyboard::Backspace)
            {
                if(shouldWatchBack)
                    shouldWatchBack=false;
                else
                    shouldWatchBack=true;
            }
            else if(event.key.code==sf::Keyboard::Up)
            {
                if(cannonAngle<89)
                    cannonAngle++;
            }
            else if(event.key.code==sf::Keyboard::Down)
            {
                if(cannonAngle>1)
                    cannonAngle--;
            }
        }
        if(event.type==sf::Event::MouseButtonPressed)
        {
            soundCannonFire.setVolume(cannonPower/10);
            soundCannonFire.play();
            shouldCannonFireBeVisible=true;
            balls.push_back(Ball(30, materialType));
            balls[numberOfBalls].setPosition(140, 650);
            balls[numberOfBalls].speedY=-(cannonAngle/90)*(0.5*cannonPower/sqrt(balls[numberOfBalls].weight))*cannonPowerMod;
            balls[numberOfBalls].speedX=(1-(cannonAngle/90))*(0.5*cannonPower/sqrt(balls[numberOfBalls].weight))*cannonPowerMod;
            if(balls[numberOfBalls].speedX<10)
                balls[numberOfBalls].speedX+=10;
            if(balls[numberOfBalls].speedX>-5)
                balls[numberOfBalls].speedY-=5;
            numberOfBalls++;
        }
        else
        {
            shouldCannonFireBeVisible=false;
        }
    }

}

void MainWindow::setViewPosition(std::vector <Ball> &balls, int numberOfBalls)
{
    if(shouldWatchBack==false)
    {
        if(numberOfBalls>0)
        {
            float offsetX;
            float offsetY;

            offsetX = balls[numberOfBalls-1].speedX/3;
            offsetY = balls[numberOfBalls-1].speedY/3;

            if(balls[numberOfBalls-1].getPosition().y+100>400)

            {
                if(balls[numberOfBalls-1].getPosition().x+100<600)
                {
                    view.setCenter(600, 400);
                }
                else
                {
                    view.setCenter(balls[numberOfBalls-1].getPosition().x+100+offsetX, 400);
                }
            }
            else
            {
                if(balls[numberOfBalls-1].getPosition().x+100<600)
                {
                    view.setCenter(600, balls[numberOfBalls-1].getPosition().y+100+offsetY);
                }
                else
                {
                    view.setCenter(balls[numberOfBalls-1].getPosition().x+100+offsetX,
                                   balls[numberOfBalls-1].getPosition().y+100+offsetY);
                }
            }

            if(balls[numberOfBalls-1].speedX==0&&balls[numberOfBalls-1].speedY==0)
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
