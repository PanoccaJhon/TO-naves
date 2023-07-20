#ifndef AVION_H
#define AVION_H
#include <string>
#include <SFML/Graphics.hpp>
class Avion: public sf::Sprite
{
public:
    Avion();
    void girar(sf::Vector2i mouse);
    void avanzar();
    void disparar(sf::Vector2i mouse);
    bool movimiento;
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
    float moveY(float X){
        return F.m*X+F.b;
    }
    float moveX(float Y){
        return (Y-F.b)/F.m;
    }
    float inX(){
        if(objetivo.x<getPosition().x)
            return getPosition().x-velocity;
        else
            return getPosition().x+velocity;
    }
    float inY(){
        if(objetivo.y<getPosition().y*(-1))
            return getPosition().y*(-1)-velocity;
        else
            return getPosition().y*(-1)+velocity;
    }
};

#endif // AVION_H
