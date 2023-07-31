#ifndef VIDA_H
#define VIDA_H

#include <SFML/Graphics.hpp>
class Vida : public sf::Sprite
{
public:
    Vida(sf::Vector2f posicion){
        this->image = "C:/Users/jpanocca/Documents/QtProjects/TO-naves/Imagenes/vida.png";
        if(!texture.loadFromFile(image))
            std::cout<<"Error: imagen -"<< EXIT_FAILURE<<std::endl;
        else{
            setTexture(texture);
            setScale(sf::Vector2f(.6f,.6f));
            setPosition(posicion);
        }
    }

 void reducirVida() {
        viva = false;
    }

 bool estaViva() const {
        return viva;
    }

private:
    std::string image;
    sf::Texture texture;
    bool viva;
};

#endif // VIDA_H
