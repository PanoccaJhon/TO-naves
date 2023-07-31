#include "asteroide.h"
#include <iostream>
Asteroide::Asteroide()
{
    this->image = "C:/Users/jpanocca/Documents/QtProjects/TO-naves/Imagenes/asteroide.png";
    if(!texture.loadFromFile(image))
        std::cout<<"Error: imagen -"<< EXIT_FAILURE<<std::endl;
    else{
        setTexture(texture);
        setScale(sf::Vector2f(.2f,.2f));
        setPosition(inicio());
        setOrigin(sf::Vector2f(547/2.f,539/2.f));
        this->velocity = 5.f;
        objetivo = getPosition();
        setObj = true;
        cambioEje = 1;
    }
}
sf::Vector2f Asteroide::inicio(){
    float x =std::rand()%(1200);
    return sf::Vector2f(x,-100);
}
void Asteroide::setObjetivo(sf::Vector2f avion){
    //PREPARAR PARA MOVIMIENTO
    objetivo = sf::Vector2f(avion.x,avion.y*(-1));
    sf::Vector2f sc = objetivo - sf::Vector2f(getPosition().x,getPosition().y*(-1));
    this->F.m = sc.y/sc.x; //Calculoar la pendiente
    this->F.b = objetivo.y - F.m*objetivo.x; //Calcular constante b
    this->F.d = 1000.f; //Calcular distancia a recorrer
    //Determinar cambio en eje
    if(std::abs(F.m)>1)
        if(objetivo.x<getPosition().x)
            cambioEje = -1;
    else
        if(objetivo.y<getPosition().y*(-1))
            cambioEje = -1;
    setObj = false;
}
void Asteroide::moverse(){
    if(F.d>0){ //Verificar si hay distancia por recorrer
        if(std::abs(F.m)>1) //verifica en cual eje avanzar
            setPosition(moveX(inY()),inY()*(-1));
        else
            setPosition(inX(),moveY(inX())*(-1));
        F.d-=velocity;
    }
}
float Asteroide::moveY(float X){
    return F.m*X+F.b;
}
float Asteroide::moveX(float Y){
    return (Y-F.b)/F.m;
}
float Asteroide::inX(){
    return getPosition().x + cambioEje*velocity;
}
float Asteroide::inY(){
    return getPosition().y*(-1)+cambioEje*velocity;
}
bool Asteroide::withobj(){
    return setObj;
}
