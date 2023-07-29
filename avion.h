#ifndef AVION_H
#define AVION_H
#include <string>
#include "mysprite.h"
#include <SFML/Graphics.hpp>
class Avion: public MySprite//sf::Sprite
{
public:
    Avion();
    void girar(sf::Vector2i mouse) override;
    void avanzar() override;
    void disparar(sf::Vector2f mouse);
private:
    std::string image;
    sf::Texture texture;
    float velocity;
    sf::Vector2f objetivo;
    struct{
        float m;
        float b;
        float d;
    }F;
    float moveY(float X);
    float moveX(float Y);
    float inX();
    float inY();

};

#endif // AVION_H
