#include <iostream>
#include <vector>
#include <string>
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

sf::Texture texFloor;
sf::Texture texCannon;
sf::Texture texCannonFire;

sf::RectangleShape shapeFloor;
sf::RectangleShape shapeCannon;
sf::RectangleShape shapeCannonFire;

sf::Image imageCannonFire;

bool shouldCannonFireBeVisible = false;
float cannonPower = 20000;
float cannonAngle = 45;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    MainWindow window(1200, 800, "Cannon simulator v0.4");
    std::vector <Ball> balls;
    int numberOfBalls = 0;
    materials materialType = wooden;

    Resources::loadSoundBuffers();
    Resources::loadSounds();
    Resources::loadFonts();
    Resources::loadTexts();
    Resources::loadImages();
    Resources::loadTextures();
    Resources::loadShapes();

    while(window.isOpen())
    {
        sf::Event event;
        window.handleEvent(event, balls, numberOfBalls, materialType);
        Resources::setTextCurrentMaterial(materialType);

        int buffor = cannonPower;
        textCurrentCannonPower.setString(std::to_string(buffor));
        buffor = cannonAngle;
        textCurrentAngle.setString(std::to_string(buffor));

        sf::Vector2f viewPos = window.view.getCenter();
        textBasicMaterial.setPosition(viewPos.x-190, viewPos.y-350);
        textCurrentMaterial.setPosition(viewPos.x+50, viewPos.y-352);
        textBasicCannonPower.setPosition(viewPos.x-312, viewPos.y-312);
        textCurrentCannonPower.setPosition(viewPos.x+50, viewPos.y-311);
        textBasicAngle.setPosition(viewPos.x-153, viewPos.y-275);
        textCurrentAngle.setPosition(viewPos.x+49, viewPos.y-274);

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
        window.display();
    }

    return 0;
}
