#include "ovni2.h"
#include <iostream>
#include <QImage>
#include <QPixmap>
Ovni2::Ovni2()
{

    QPixmap pixmap(":/Imagenes/enemigoInfo.png");
    QImage image = pixmap.toImage();
    QString temFi = "tem_enemigoInfo.png";
    image.save(temFi);
    if(!texture.loadFromFile(temFi.toStdString()))
    //this->image = "C:/Users/jpanocca/Documents/QtProjects/TO-naves/Imagenes/enemigoInfo.png";
    //if(!texture.loadFromFile(image))
        std::cout<<"Error: imagen -"<< EXIT_FAILURE<<std::endl;
    else{
        setTexture(texture);
        setScale(sf::Vector2f(.2f,.2f));
        setPosition(inicio());
        setOrigin(sf::Vector2f(547/2.f,539/2.f));
        this->velocity = 3.f;
        objetivo = getPosition();
        cambioEje = 1;
    }
}
sf::Vector2f Ovni2::inicio(){
    float y =std::rand()%(768);
    return sf::Vector2f(-50,y);
}
void Ovni2::setObjetivo(sf::Vector2f avion){
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

}

void Ovni2::moverse(){
    if(std::abs(F.m)>1) //verifica en cual eje avanzar
        setPosition(moveX(inY()),inY()*(-1));//Cambia en X
    else
        setPosition(inX(),moveY(inX())*(-1));//Cambia en Y
}

float Ovni2::moveY(float X){
    return F.m*X+F.b;
}
float Ovni2::moveX(float Y){
    return (Y-F.b)/F.m;
}
float Ovni2::inX(){
    return getPosition().x + cambioEje*velocity;
}
float Ovni2::inY(){
    return getPosition().y*(-1)+cambioEje*velocity;
}
