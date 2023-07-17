#include "avion.h"
#include <iostream>
#include <cmath>
Avion::Avion()
{
    if(!texture.loadFromFile("C:\\Users\\jpanocca\\Downloads\\sprite-avion.png"))
        std::cout<<"Error: imagen -"<< EXIT_FAILURE<<std::endl;
    else{
        setTexture(texture);
        setScale(sf::Vector2f(.2f,.2f));
        setPosition(sf::Vector2f(500.f,400.f));
        setOrigin(sf::Vector2f(547/2.f,539/2.f));
        setRotation(90.f);
    }

}


void Avion::girar(sf::Vector2i mouse)
{
    sf::Vector2f mousePos= sf::Vector2f(mouse);

    mousePos.y = mousePos.y*(-1);
    std::cout<<"Mouse "<<mousePos.x<<","<<mousePos.y<<std::endl;
    sf::Vector2f spritePos = getPosition();
    spritePos.y = spritePos.y*(-1);
    sf::Vector2f sc = mousePos-spritePos;
    float ang = std::atan2(sc.y,sc.x);
    ang = 90.f-ang*(180/M_PI);
    if(ang<0.f)
        ang+=360.f;
    setRotation(ang);
}

void Avion::avanzar(sf::Vector2i &mouse)
{

}
/*
sf::RenderWindow &window;
std::string image;
sf::Texture texture;
sf::Sprite sprite;
float velocity;
*/
