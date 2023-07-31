#ifndef OVNI2_H
#define OVNI2_H
#include "mysprite.h"
#include <string>
#include <SFML/Graphics.hpp>
class Ovni2: public MySprite//sf::Sprite
{
public:
    Ovni2();
    void setObjetivo(sf::Vector2f avion);
    void moverse();

private:
    std::string image;
    sf::Texture texture;
    float velocity;
    sf::Vector2f inicio();
    sf::Vector2f objetivo;
    struct{
        float m=0.f;
        float b=0.f;
        float d=0.f;
    }F;
    float moveY(float X);
    float moveX(float Y);
    float inX();
    float inY();
    float cambioEje;

};

#endif // OVNI2_H
