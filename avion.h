#ifndef AVION_H
#define AVION_H
#include <string>
#include "mysprite.h"
#include <SFML/Graphics.hpp>
#include "Disparar.h"
class Avion: public MySprite//sf::Sprite
{
public:
    Avion();
    void girar(sf::Vector2i mouse) override;
    void avanzar() override;
    void disparar() override;
    //int getVidas() override;
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

    Disparar disparador;

};

#endif // AVION_H
