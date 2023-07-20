#include "avion.h"
#include <iostream>
#include <cmath>
#include <iostream>
Avion::Avion()
{
    this->image = "C:/Users/jpanocca/Downloads/sprite-avion.png";
    if(!texture.loadFromFile(image))
        std::cout<<"Error: imagen -"<< EXIT_FAILURE<<std::endl;
    else{
        setTexture(texture);
        setScale(sf::Vector2f(.2f,.2f));
        setPosition(sf::Vector2f(500.f,400.f));
        setOrigin(sf::Vector2f(547/2.f,539/2.f));
        setRotation(90.f);
        this->velocity = 5.f;
        this->movimiento = false;
        this->F.m = 0.f;
        this->F.b = 0.f;
        this->F.d = 0.f;
    }

}


void Avion::girar(sf::Vector2i mouse)
{
    this->objetivo = sf::Vector2f(mouse.x,mouse.y*(-1));

    sf::Vector2f spritePos = getPosition();
    spritePos.y = spritePos.y*(-1);
    sf::Vector2f sc = objetivo-spritePos;
    float ang = std::atan2(sc.y,sc.x);
    ang = 90.f-ang*(180/M_PI);
    if(ang<0.f)
        ang+=360.f;
    setRotation(ang);

    //PREPARAR PARA MOVIMIENTO
    this->F.m = sc.y/sc.x; //Calculoar la pendiente
    this->F.b = objetivo.y - F.m*objetivo.x; //Calcular constante b
    this->F.d = std::abs(F.m)<1?std::abs(sc.x):std::abs(sc.y); //Calcular distancia a recorrer
    this->movimiento = true;
}


void Avion::avanzar()
{
    if(F.d>0){ //Verificar si hay distancia por recorrer
        if(std::abs(F.m)>1) //verifica en cual eje avanzar
            setPosition(moveX(inY()),inY()*(-1));
        else
            setPosition(inX(),moveY(inX())*(-1));
        F.d-=velocity;
    }else
        this->movimiento = false;
}

void Avion::disparar(sf::Vector2i mouse)
{

}
/*
sf::RenderWindow &window;
std::string image;
sf::Texture texture;
sf::Sprite sprite;
float velocity;
*/
