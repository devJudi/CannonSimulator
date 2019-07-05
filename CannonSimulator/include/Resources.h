#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "MainWindow.h"

extern sf::SoundBuffer soundBufferWooden;
extern sf::SoundBuffer soundBufferRubber;
extern sf::SoundBuffer soundBufferMetal;
extern sf::SoundBuffer soundBufferAether;
extern sf::SoundBuffer soundBufferPulsar;
extern sf::SoundBuffer soundBufferCannonFire;

extern sf::Sound soundWooden;
extern sf::Sound soundRubber;
extern sf::Sound soundMetal;
extern sf::Sound soundAether;
extern sf::Sound soundPulsar;
extern sf::Sound soundCannonFire;

extern sf::Text textBasicMaterial;
extern sf::Text textCurrentMaterial;
extern sf::Text textBasicCannonPower;
extern sf::Text textCurrentCannonPower;
extern sf::Text textBasicAngle;
extern sf::Text textCurrentAngle;
extern sf::Text textBasicXPosition;
extern sf::Text textCurrentXPosition;
extern sf::Text textBasicYPosition;
extern sf::Text textCurrentYPosition;
extern sf::Text textBasicPreviousXPosition;
extern sf::Text textCurrentPreviousXPosition;
extern sf::Text textBasicPreviousYPosition;
extern sf::Text textCurrentPreviousYPosition;

extern sf::Texture texFloor;
extern sf::Texture texCannon;
extern sf::Texture texCannonFire;

extern sf::RectangleShape shapeFloor;
extern sf::RectangleShape shapeCannon;
extern sf::RectangleShape shapeCannonFire;

extern sf::Image imageCannonFire;

extern sf::Font fontPixel;

extern bool shouldCannonFireBeVisible;
extern float cannonPower;
extern float cannonAngle;

class Resources
{
    public:
        Resources();
        virtual ~Resources();

        static void loadSoundBuffers();
        static void loadSounds();
        static void loadFonts();
        static void loadTexts();
        static void loadImages();
        static void loadTextures();
        static void loadShapes();

        static void setTextCurrentMaterial(materials material);
        static void updateTexts(materials material, sf::Vector2f viewPos, sf::Vector2f ballPos);

    protected:

    private:
};

#endif // RESOURCES_H
