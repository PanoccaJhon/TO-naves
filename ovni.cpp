#include "ovni.h"
#include <iostream>
Ovni::Ovni()
{
    this->image = "C:/Users/jpanocca/Downloads/sprite-avion.png";
    if(!texture.loadFromFile(image))
        std::cout<<"Error: imagen -"<< EXIT_FAILURE<<std::endl;
    else{
        setTexture(texture);
        setScale(sf::Vector2f(.2f,.2f));
        setPosition(inicio());
        setOrigin(sf::Vector2f(547/2.f,539/2.f));
        this->velocity = 5.f;

    }
}
sf::Vector2f Ovni::inicio(){
    return sf::Vector2f(200,600);
}
