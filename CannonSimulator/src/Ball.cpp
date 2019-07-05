#include "Ball.h"

Ball::Ball(int radius, materials material, int points)
    :CircleShape(radius, points)
{
    speedY = 0;
    speedX = 20;
    accelerationY = 0.981;
    this->setOrigin((radius*2)/2, (radius*2)/2);
    ballMaterial = material;
    willBallBeOutOfFloor = false;

    switch (material)
    {
    case wooden:
    {
        this->setFillColor(sf::Color(220, 100, 0, 240));
        bounciness = 1;
        weight = 76.84;
        break;
    }
    case rubber:
    {
        this->setFillColor(sf::Color(220, 20, 100, 220));
        bounciness = 2.5;
        weight = 158.2;
        break;
    }
    case metal:
    {
        this->setFillColor(sf::Color(100, 100, 100, 255));
        bounciness = 0.5;
        weight = 881.4;
        break;
    }
    case aether:
    {
        this->setFillColor(sf::Color(255, 255, 10, 255));
        bounciness = 1.2;
        weight = 33.9;
        break;
    }
    case pulsar:
    {
        bounciness = 0.01;
        this->setFillColor(sf::Color(10, 10, 10, 255));
        this->setOutlineThickness(-1);
        this->setOutlineColor(sf::Color::White);
        weight = 113000;
        break;
    }
    }

    maxSpeedY = 1.6*weight;

}

Ball::~Ball()
{
    //dtor
}
/*
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
            {
                 speedY/=-2;
                 if(speedY*speedY>100)   soundWooden.setVolume(100);
                 else if(speedY*speedY>64)   soundWooden.setVolume(80);
                 else if(speedY*speedY>36)   soundWooden.setVolume(60);
                 else if(speedY*speedY>16)   soundWooden.setVolume(40);
                 else   soundWooden.setVolume(20);
                 soundWooden.play();
            }
            else if(ballMaterial==rubber)
            {
                speedY/=-1.4;
                if(speedY*speedY>100)   soundRubber.setVolume(100);
                else if(speedY*speedY>64)   soundRubber.setVolume(80);
                else if(speedY*speedY>36)   soundRubber.setVolume(60);
                else if(speedY*speedY>16)   soundRubber.setVolume(40);
                else   soundRubber.setVolume(20);
                soundRubber.play();
            }
            else if(ballMaterial==metal)
            {
                speedY/=-4;
                if(speedY*speedY>100)   soundMetal.setVolume(100);
                else if(speedY*speedY>64)   soundMetal.setVolume(80);
                else if(speedY*speedY>36)   soundMetal.setVolume(60);
                else if(speedY*speedY>16)   soundMetal.setVolume(40);
                else   soundMetal.setVolume(20);
                soundMetal.play();
            }
            else if(ballMaterial==aether)
            {
                speedY/=-1.1;
                if(speedY*speedY>100)   soundAether.setVolume(100);
                else if(speedY*speedY>64)   soundAether.setVolume(80);
                else if(speedY*speedY>36)   soundAether.setVolume(60);
                else if(speedY*speedY>16)   soundAether.setVolume(40);
                else   soundAether.setVolume(20);
                soundAether.play();
            }
            else if(ballMaterial==pulsar)
            {
                speedY/=-80;
                if(speedY*speedY>100)   soundPulsar.setVolume(100);
                else if(speedY*speedY>64)   soundPulsar.setVolume(80);
                else if(speedY*speedY>36)   soundPulsar.setVolume(60);
                else if(speedY*speedY>16)   soundPulsar.setVolume(40);
                else   soundPulsar.setVolume(20);
                soundPulsar.play();
            }

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
        this->move(speedX, mod*speedY);
    }
}
*/
bool Ball::isBallTouchingGround(int floorPosition)
{
    return (this->getPosition().y+(this->getRadius())>=floorPosition);
}

bool Ball::isBallStoped(int floorPosition)
{
    return speedX==0&&speedY==0&&isBallTouchingGround(floorPosition);
}

void Ball::doGravity(int floorPosition)
{
    if(!isBallTouchingGround(floorPosition))
    {
        if(floorPosition-(this->getPosition().y+this->getRadius())<speedY)
        {
            willBallBeOutOfFloor=true;
        }
        else
        {
            willBallBeOutOfFloor=false;
        }

        if(!(speedY>maxSpeedY)) speedY+=accelerationY;
        else speedY=maxSpeedY;

        if(willBallBeOutOfFloor) this->move(0, floorPosition-(this->getPosition().y+this->getRadius()));
        else this->move(0, speedY);

        if(speedX>20)
        {
            speedX-=0.1;
            this->move(speedX, 0);
        }
        else if(speedX>10)
        {
            speedX/=1.05;
            this->move(speedX, 0);
        }
        else
        {
           speedX/=1.002;
            this->move(speedX, 0);
        }
    }
    else
    {
        if(speedY>1/bounciness*15)
        {
            speedY=(-1)*(speedY-(1/bounciness)*15);
            this->move(sf::Vector2f(0, speedY));
        }
        else
        {
            speedY=0;
        }

        if(speedX>weight/200)
        {
            speedX-=0.3*(weight/110);
            this->move(speedX, 0);
        }
        else
            speedX=0;
    }

}
