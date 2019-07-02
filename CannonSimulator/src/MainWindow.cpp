#include "MainWindow.h"

MainWindow::MainWindow(int x, int y, std::string name, int fps)
    :RenderWindow(sf::VideoMode(x, y), name)
{
    view.setSize(1200, 800);
    view.setCenter(600, 400);
    this->setView(view);
    this->setFramerateLimit(fps);
}

MainWindow::~MainWindow()
{
    //dtor
}

void MainWindow::loadSounds()
{
    woodenSoundBuffer.loadFromFile("sounds/wooden.flac");
    rubberSoundBuffer.loadFromFile("sounds/rubber.flac");
    metalSoundBuffer.loadFromFile("sounds/metal.flac");
    aetherSoundBuffer.loadFromFile("sounds/aether.flac");
    pulsarSoundBuffer.loadFromFile("sounds/pulsar.flac");

    woodenSound.setBuffer(woodenSoundBuffer);
    rubberSound.setBuffer(rubberSoundBuffer);
    metalSound.setBuffer(metalSoundBuffer);
    aetherSound.setBuffer(aetherSoundBuffer);
    pulsarSound.setBuffer(pulsarSoundBuffer);
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
        }
        if(event.type==sf::Event::MouseButtonPressed)
        {
            //sf::Window *window = this;
            //sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            balls.push_back(Ball(30, materialType));
            balls[numberOfBalls].setPosition(140, 650);
            balls[numberOfBalls].speedY=-40;
            numberOfBalls++;
        }
    }

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
        else std::cout<<balls[numberOfBalls-1].speedX<<std::endl;
        this->setView(view);
    }


}
