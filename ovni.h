#ifndef OVNI_H
#define OVNI_H

#include <string>
#include <SFML/Graphics.hpp>
class Ovni: public sf::Sprite
{
public:
    Ovni();
private:
    std::string image;
    sf::Texture texture;
    float velocity;
    sf::Vector2f inicio();
};

#endif // OVNI_H
