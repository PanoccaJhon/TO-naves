#ifndef OVNI_H
#define OVNI_H
#include "mysprite.h"
#include <string>
#include <SFML/Graphics.hpp>
class Ovni: public MySprite//sf::Sprite
{
public:
    Ovni();
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

#endif // OVNI_H
