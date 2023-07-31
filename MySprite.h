#ifndef MYSPRITE_H
#define MYSPRITE_H
#include <SFML/Graphics.hpp>

class MySprite: public sf::Sprite
{
public:
    virtual void girar(sf::Vector2i mouse) {}
    virtual void avanzar() {}
    virtual void disparar() {}
    bool movimiento = false;
    virtual void moverse() {}
    virtual void setObjetivo(sf::Vector2f) {}
    virtual bool withobj() { return NULL;}
    int getVidas() { return vidas;}
    int vidas = 4;
};
#endif // MYSPRITE_H
