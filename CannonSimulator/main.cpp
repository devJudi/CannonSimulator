#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Resources.h"
#include "MainWindow.h"
#include "Ball.h"

//////////////////////////////////////GLOBAL VARIABLES AND OBJECTS/////////////////////////////////////////////
sf::Font fontPixel;

sf::SoundBuffer soundBufferWooden;
sf::SoundBuffer soundBufferRubber;
sf::SoundBuffer soundBufferMetal;
sf::SoundBuffer soundBufferAether;
sf::SoundBuffer soundBufferPulsar;
sf::SoundBuffer soundBufferCannonFire;

sf::Sound soundWooden;
sf::Sound soundRubber;
sf::Sound soundMetal;
sf::Sound soundAether;
sf::Sound soundPulsar;
sf::Sound soundCannonFire;

sf::Text textBasicMaterial("Current material: ", fontPixel, 15);
sf::Text textCurrentMaterial("K", fontPixel, 18);
sf::Text textBasicCannonPower("Current power of cannon: ", fontPixel, 15);
sf::Text textCurrentCannonPower("K", fontPixel, 18);
sf::Text textBasicAngle("Current angle: ", fontPixel, 15);
sf::Text textCurrentAngle("45", fontPixel, 18);

sf::Text textBasicXPosition("X: ", fontPixel, 16);
sf::Text textCurrentXPosition(":V", fontPixel, 17);
sf::Text textBasicYPosition("Y: ", fontPixel, 16);
sf::Text textCurrentYPosition("V:", fontPixel, 17);

sf::Text textBasicPreviousXPosition("Previous X: ", fontPixel, 12);
sf::Text textCurrentPreviousXPosition(" - ", fontPixel, 13);
sf::Text textBasicPreviousYPosition("Previous Y: ", fontPixel, 12);
sf::Text textCurrentPreviousYPosition(" - ", fontPixel, 13);

sf::Texture texFloor;
sf::Texture texCannon;
sf::Texture texCannonFire;

sf::RectangleShape shapeFloor;
sf::RectangleShape shapeCannon;
sf::RectangleShape shapeCannonFire;

sf::Image imageCannonFire;

bool shouldCannonFireBeVisible = false;
float cannonPower = 100;
float cannonPowerMod = 20;
float cannonAngle = 45;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Resources::loadSoundBuffers();
    Resources::loadSounds();
    Resources::loadFonts();
    Resources::loadTexts();
    Resources::loadImages();
    Resources::loadTextures();
    Resources::loadShapes();

    std::vector <Ball> balls;
    int numberOfBalls = 0;
    std::string previousXPositionBuffer = " - ";
    std::string previousYPositionBuffer = " - ";
    materials materialType = wooden;

    MainWindow window(1200, 800, "Cannon simulator v0.4");
    while(window.isOpen())
    {
        sf::Event event;
        window.handleEvent(event, balls, numberOfBalls, materialType);

        sf::Vector2f viewPos = window.view.getCenter();
        if(numberOfBalls>0)
        {
            if(!balls[numberOfBalls-1].isBallStoped())
            {
                Resources::updateTexts(materialType, viewPos,
                                                   balls[numberOfBalls-1].getPosition());
            }
            else
            {
                previousXPositionBuffer = textCurrentXPosition.getString();

                Resources::updateTexts(materialType, viewPos,
                                                   balls[numberOfBalls].getPosition());
            }
        }
        else Resources::updateTexts(materialType, viewPos,
                                                   sf::Vector2f(0, 0));


        textCurrentPreviousYPosition.setString(previousYPositionBuffer);

        if(previousXPositionBuffer!="0")   textCurrentPreviousXPosition.setString(previousXPositionBuffer);

        window.clear(sf::Color(50, 50, 50, 255));

        window.draw(shapeFloor);
        window.draw(shapeCannon);
        for(int i = 0; i<numberOfBalls; i++)
        {
            balls[i].doGravity(shapeFloor.getPosition().y);
            window.draw(balls[i]);
        }
        if(shouldCannonFireBeVisible) window.draw(shapeCannonFire);

        window.draw(textBasicMaterial);
        window.draw(textCurrentMaterial);

        window.draw(textBasicCannonPower);
        window.draw(textCurrentCannonPower);

        window.draw(textBasicAngle);
        window.draw(textCurrentAngle);

        window.draw(textBasicXPosition);
        window.draw(textCurrentXPosition);
        window.draw(textBasicYPosition);
        window.draw(textCurrentYPosition);

        window.draw(textBasicPreviousXPosition);
        window.draw(textCurrentPreviousXPosition);

        window.display();
    }

    return 0;
}
