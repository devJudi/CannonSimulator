#include "Resources.h"

Resources::Resources()
{
    //ctor
}

Resources::~Resources()
{
    //dtor
}

void Resources::loadSoundBuffers()
{
    soundBufferWooden.loadFromFile("sounds/wooden.flac");
    soundBufferRubber.loadFromFile("sounds/rubber.flac");
    soundBufferMetal.loadFromFile("sounds/metal.flac");
    soundBufferAether.loadFromFile("sounds/aether.flac");
    soundBufferPulsar.loadFromFile("sounds/pulsar.flac");
    soundBufferCannonFire.loadFromFile("sounds/cannonFire.flac");
}

void Resources::loadSounds()
{
    soundWooden.setBuffer(soundBufferWooden);
    soundRubber.setBuffer(soundBufferRubber);
    soundMetal.setBuffer(soundBufferMetal);
    soundAether.setBuffer(soundBufferAether);
    soundPulsar.setBuffer(soundBufferPulsar);
    soundCannonFire.setBuffer(soundBufferCannonFire);
}

void Resources::loadFonts()
{
    fontPixel.loadFromFile("fonts/pixelFont.ttf");
}

void Resources::loadTexts()
{
    textCurrentCannonPower.setFillColor(sf::Color::Red);
    textCurrentAngle.setFillColor(sf::Color::Yellow);
    textCurrentXPosition.setFillColor(sf::Color::Green);
    textCurrentYPosition.setFillColor(sf::Color::Green);
}

void Resources::loadImages()
{
    imageCannonFire.loadFromFile("img/cannonFire.jpg");
    imageCannonFire.createMaskFromColor(sf::Color::White);
}

void Resources::loadTextures()
{
    texFloor.loadFromFile("img/floor.png");
    texCannon.loadFromFile("img/cannon.jpg");
    texCannonFire.loadFromImage(imageCannonFire, sf::IntRect(0, 0, 1300, 1300));
}

void Resources::loadShapes()
{
    shapeFloor.setSize(sf::Vector2f(384000, 10));
    shapeFloor.setPosition(0, 790);
    shapeFloor.setTexture(&texFloor, false);

    shapeCannon.setSize(sf::Vector2f(150, 150));
    shapeCannon.setPosition(0, 640);
    shapeCannon.setTexture(&texCannon, true);


    shapeCannonFire.setSize(sf::Vector2f(100, 100));
    shapeCannonFire.setPosition(158, 558);
    shapeCannonFire.setRotation(42.5);
    shapeCannonFire.setTexture(&texCannonFire, true);
}

void Resources::setTextCurrentMaterial(materials material)
{
    switch(material)
    {
    case wooden:
        {
            textCurrentMaterial.setString("wooden");
            textCurrentMaterial.setOutlineThickness(0);
            textCurrentMaterial.setLetterSpacing(1);
            textCurrentMaterial.setFillColor(sf::Color(220, 100, 0, 240));
            break;
        }
    case rubber:
        {
            textCurrentMaterial.setString("rubber");
            textCurrentMaterial.setOutlineThickness(0);
            textCurrentMaterial.setLetterSpacing(1);
            textCurrentMaterial.setFillColor(sf::Color(220, 20, 100, 220));
            break;
        }
    case metal:
        {
            textCurrentMaterial.setString("metal");
            textCurrentMaterial.setOutlineThickness(0);
            textCurrentMaterial.setLetterSpacing(1);
            textCurrentMaterial.setFillColor(sf::Color(100, 100, 100, 255));
            break;
        }
    case aether:
        {
            textCurrentMaterial.setString("aether");
            textCurrentMaterial.setOutlineThickness(0);
            textCurrentMaterial.setLetterSpacing(1);
            textCurrentMaterial.setFillColor(sf::Color(255, 255, 0, 255));
            break;
        }
    case pulsar:
        {
            textCurrentMaterial.setString("pulsar");
            textCurrentMaterial.setOutlineColor(sf::Color::White);
            textCurrentMaterial.setOutlineThickness(1);
            textCurrentMaterial.setLetterSpacing(2);
            textCurrentMaterial.setFillColor(sf::Color(25, 25, 25, 255));
            break;
        }
    }
}

void Resources::updateTexts(materials material, sf::Vector2f viewPos, sf::Vector2f ballPos)
{
    setTextCurrentMaterial(material);

    int buffor = cannonPower;
    textCurrentCannonPower.setString(std::to_string(buffor));

    buffor = cannonAngle;
    textCurrentAngle.setString(std::to_string(buffor));

    buffor = ballPos.x;
    textCurrentXPosition.setString(std::to_string(buffor));

    buffor = ballPos.y;
    textCurrentYPosition.setString(std::to_string(buffor));

    textBasicMaterial.setPosition(viewPos.x-190, viewPos.y-350);
    textCurrentMaterial.setPosition(viewPos.x+50, viewPos.y-352);

    textBasicCannonPower.setPosition(viewPos.x-312, viewPos.y-312);
    textCurrentCannonPower.setPosition(viewPos.x+50, viewPos.y-311);

    textBasicAngle.setPosition(viewPos.x-153, viewPos.y-275);
    textCurrentAngle.setPosition(viewPos.x+49, viewPos.y-274);

    textBasicXPosition.setPosition(viewPos.x+470, viewPos.y-365);
    textCurrentXPosition.setPosition(viewPos.x+510, viewPos.y-366);
    textBasicYPosition.setPosition(viewPos.x+470, viewPos.y-325);
    textCurrentYPosition.setPosition(viewPos.x+510, viewPos.y-326);

    textBasicPreviousXPosition.setPosition(viewPos.x+420, viewPos.y-285);
    textCurrentPreviousXPosition.setPosition(viewPos.x+550, viewPos.y-286);
    textBasicPreviousYPosition.setPosition(viewPos.x+420, viewPos.y-255);
    textCurrentPreviousYPosition.setPosition(viewPos.x+550, viewPos.y-256);
}

