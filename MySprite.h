#ifndef MYSPRITE_H
#define MYSPRITE_H
#include <SFML/Graphics.hpp>

class MySprite: public sf::Sprite
{
public:
    virtual void girar(sf::Vector2i mouse)=0;
    virtual void avanzar()=0;
    virtual void disparar(sf::Vector2i mouse)=0;
    bool movimiento;
};
#endif // MYSPRITE_H
