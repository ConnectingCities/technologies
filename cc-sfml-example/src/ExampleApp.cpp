#include <iostream>
#include "ExampleApp.h"

using namespace sf;

ExampleApp::ExampleApp() : RenderWindow(VideoMode(800,600), "ExampleApp"), targetPosition(400.f, 300.f), animCount(0), animLength(50), startOK(true)
{
    RenderWindow::setVerticalSyncEnabled(true);

    if (clickSoundBuffer.loadFromFile("../res/click.wav"))
    {
        clickSound.setBuffer(clickSoundBuffer);
        clickSound.setLoop(false);
    }
    else
    {
        std::cout << "Unable to load sound file!" << std::endl;
        startOK = false;
    }

    if (bgTexture.loadFromFile("../res/background.png"))
    {
        bgSprite.setTexture(bgTexture);
    }
    else
    {
        std::cout << "Unable to load background file!" << std::endl;
        startOK = false;
    }

    if (objectTexture.loadFromFile("../res/object.png"))
    {
        objectSprite.setTexture(objectTexture);
        objectSprite.setPosition(368.f, 268.f);
    }
    else
    {
        std::cout << "Unable to load object file!" << std::endl;
        startOK = false;
    }

    font.loadFromFile("../res/Ubuntu-L.ttf");
    infoText.setString(String("Click in the window to let the cursor follow the mouse position."));
    infoText.setFont(font);
    infoText.setPosition(10.f, 10.f);
    infoText.setScale(0.75f, 0.75f);

}

ExampleApp::~ExampleApp()
{

}

bool ExampleApp::wasStartOK()
{
    return startOK;
}

void ExampleApp::update()
{
    Event event;
    while (RenderWindow::pollEvent(event))
    {
        if (event.type == Event::Closed)
            RenderWindow::close();
    }

    Vector2i mousePos = Mouse::getPosition(*this);
    Vector2u winSize = RenderWindow::getSize();

    if (mousePos.x > 0 && mousePos.x < (int)winSize.x && mousePos.y > 0 && mousePos.y < (int)winSize.y)
    {
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (clickSound.getStatus() == Sound::Stopped)
            {
                clickSound.play();
                targetPosition.x = (float)mousePos.x;
                targetPosition.y = (float)mousePos.y;
                targetVector.x = (targetPosition.x - objectSprite.getPosition().x - 32.f) / (float)animLength;
                targetVector.y = (targetPosition.y - objectSprite.getPosition().y - 32.f) / (float)animLength;

                animCount = 0;
            }
        }
    }
    if (animCount < animLength)
    {
        objectSprite.move(targetVector.x, targetVector.y);
        animCount++;
    }
}

void ExampleApp::run()
{
    while (RenderWindow::isOpen())
    {
        update();

        RenderWindow::clear(Color::White);

        RenderWindow::draw(bgSprite);

        RenderWindow::draw(objectSprite);


        RenderWindow::draw(infoText);

        RenderWindow::display();
    }
}
