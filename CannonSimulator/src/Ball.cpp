#include "Ball.h"

Ball::Ball(int radius, materials material, int points)
    :CircleShape(radius, points)
{
    speedY = 0;
    speedX = 20;
    weight = 1;
    mod = 0.5;
    this->setOrigin((radius*2)/2, (radius*2)/2);
    ballMaterial = material;

    switch (material)
    {
    case wooden:
        {
            this->setFillColor(sf::Color(220, 100, 0, 240));
            break;
        }
    case rubber:
        {
            this->setFillColor(sf::Color(220, 20, 100, 220));
            break;
        }
    case metal:
        {
            this->setFillColor(sf::Color(100, 100, 100, 255));
            break;
        }
    case aether:
        {
            this->setFillColor(sf::Color(255, 255, 10, 255));
            break;
        }
    case pulsar:
        {
            this->setFillColor(sf::Color(10, 10, 10, 255));
            this->setOutlineThickness(-1);
            this->setOutlineColor(sf::Color::White);
            break;
        }
    }

}

Ball::~Ball()
{
    //dtor
}

void Ball::doGravity(int floorPosition)
{
    if(speedX>10) speedX-=0.02;
    else if(speedX>50) speedX-=0.015;
    else if(speedX>0) speedX-=0.01;

    if(this->getPosition().y+this->getRadius()>=floorPosition)
    {
        this->setPosition(this->getPosition().x, floorPosition-this->getRadius());
        if(speedY>3)
        {
            if(ballMaterial==wooden)
                speedY/=-2;
            else if(ballMaterial==rubber)
                speedY/=-1.4;
            else if(ballMaterial==metal)
                speedY/=-4;
            else if(ballMaterial==aether)
                speedY/=-1.1;
            else if(ballMaterial==pulsar)
                speedY/=-80;

            this->move(0, -1);
        }
        else
        {
            speedY = 0;
            if(speedX>2)
            {
                speedX-=0.5;
                this->move(speedX, 0);
            }
        }
    }
    else
    {
        speedY+=1;
        this->move(speedX, mod*(speedY*weight));
    }
}
