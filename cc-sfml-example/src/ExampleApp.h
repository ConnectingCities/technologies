#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ExampleApp : public sf::RenderWindow
{
public:
    ExampleApp();
    ~ExampleApp();


    bool wasStartOK();
    void run();

private:
    void update();

    sf::Sound clickSound;
    sf::SoundBuffer clickSoundBuffer;

    sf::Texture bgTexture;
    sf::Texture objectTexture;

    sf::Sprite bgSprite;
    sf::Sprite objectSprite;

    sf::Text infoText;
    sf::Font font;

    sf::Vector2f targetPosition, targetVector;

    unsigned int animCount, animLength;

    bool startOK;
};
