#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include "mysprite.h"
#include <string>
#include <SFML/Graphics.hpp>
class Asteroide: public MySprite//sf::Sprite
{
public:
    Asteroide();
    void setObjetivo(sf::Vector2f avion);
    void moverse();
    bool withobj();
private:
    std::string image;
    sf::Texture texture;
    float velocity;
    sf::Vector2f objetivo;
    bool setObj;
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
    sf::Vector2f inicio();

};

#endif // ASTEROIDE_H
