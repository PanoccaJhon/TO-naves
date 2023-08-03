#ifndef VIDA_H
#define VIDA_H

#include <SFML/Graphics.hpp>
#include <QImage>
#include <QPixmap>
class Vida : public sf::Sprite
{
public:
    Vida(sf::Vector2f posicion){

        QPixmap pixmap(":/Imagenes/vida.png");
        QImage image = pixmap.toImage();
        QString temFi = "tem_vida.png";
        image.save(temFi);
        if(!texture.loadFromFile(temFi.toStdString()))
        //this->image = "C:/Users/jpanocca/Documents/QtProjects/TO-naves/Imagenes/vida.png";
       // if(!texture.loadFromFile(image))
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
