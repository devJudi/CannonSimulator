#include <iostream>
#include <vector>
#include "MainWindow.h"
#include "Ball.h"

int main()
{
    MainWindow window(800, 600, "Cannon simulator v0.1");
    std::vector <Ball> balls;
    int numberOfBalls = 0;
    materials materialType = wooden;

    sf::RectangleShape floor;
    floor.setSize(sf::Vector2f(800, 10));
    floor.setFillColor(sf::Color::White);
    floor.setPosition(0, 590);

    sf::Font pixelFont;
    pixelFont.loadFromFile("fonts/pixelFont.ttf");

    sf::Text basicMaterialText("Current material: ", pixelFont, 15);
    basicMaterialText.setPosition(425, 40);

    sf::Text currentMaterial("K", pixelFont, 18);
    currentMaterial.setPosition(663, 38);

    while(window.isOpen())
    {
        sf::Event event;
        window.handleEvent(event, balls, numberOfBalls, materialType);
        if(materialType==0)
        {
            currentMaterial.setString("wooden");
            currentMaterial.setOutlineThickness(0);
            currentMaterial.setLetterSpacing(1);
            currentMaterial.setFillColor(sf::Color(220, 100, 0, 240));
        }
        else if(materialType==1)
        {
            currentMaterial.setString("rubber");
            currentMaterial.setOutlineThickness(0);
            currentMaterial.setLetterSpacing(1);
            currentMaterial.setFillColor(sf::Color(220, 20, 100, 220));
        }
        else if(materialType==2)
        {
            currentMaterial.setString("metal");
            currentMaterial.setOutlineThickness(0);
            currentMaterial.setLetterSpacing(1);
            currentMaterial.setFillColor(sf::Color(100, 100, 100, 255));
        }
        else if(materialType==3)
        {
            currentMaterial.setString("aether");
            currentMaterial.setOutlineThickness(0);
            currentMaterial.setLetterSpacing(1);
            currentMaterial.setFillColor(sf::Color(255, 255, 0, 255));
        }
        else if(materialType==4)
        {
            currentMaterial.setString("pulsar");
            currentMaterial.setOutlineColor(sf::Color::White);
            currentMaterial.setOutlineThickness(1);
            currentMaterial.setLetterSpacing(2);
            currentMaterial.setFillColor(sf::Color(25, 25, 25, 255));
        }

        window.clear();
        window.draw(floor);
        for(int i = 0; i<numberOfBalls; i++)
        {
            balls[i].doGravity(floor.getPosition().y);
            window.draw(balls[i]);
        }
        window.draw(basicMaterialText);
        window.draw(currentMaterial);
        window.display();
    }
    std::cout<<materialType<<std::endl;

    return 0;
}
