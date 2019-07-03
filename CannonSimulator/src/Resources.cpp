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

