#include "Disparar.h"
#include <iostream>
#include <QImage>
#include <QPixmap>

Disparar::Disparar(sf::Keyboard::Key teclado): tecla(teclado){}

Disparar::Disparar(){

    QPixmap pixmap(":/Imagenes/misil.png"); //carga la imagen desde imagen.qrc
    QImage image = pixmap.toImage(); //convierte QPixmap a QImage
    QString temFi = "tem_misil.png"; // guarda la imagen temporar para obtener su ruta
    image.save(temFi);

    //carga la textura de SFML desde TemFi
    if (!texture_bala.loadFromFile(temFi.toStdString())) {
        std::cout << "No existe objeto"<<std::endl;
    }

    bala.setTexture(texture_bala);
    bala.setScale(sf::Vector2f(.2f, .2f));//tamaño de la bala
    bala.setOrigin(sf::Vector2f(30.f, 30.f));
    //velocity = sf::Vector2f(0.f, -5.f); // Velocidad de movimiento del disparo
}
//obtiene la direccion que la bala debe moverse con respecto al angulo de disparo
sf::Vector2f Disparar::getDirectionVector(float angle) {
    float radianAngle = (angle - 90.f) * static_cast<float>(M_PI) / 180.f;
    return sf::Vector2f(std::cos(radianAngle), std::sin(radianAngle));
}
void Disparar::disparar(sf::Vector2f posicion, float angle) {
    sf::Sprite newBala = bala; // crea nueva bala
    newBala.setPosition(posicion); // obtiene la posicion de la bala
    sf::Vector2f direction = getDirectionVector(angle); // obtiene el angulo de giro del avion
    newBala.setRotation(angle);
    velocities.push_back(direction*10.f); // velocidad
    newBala.move(velocities.back()*3.f);//posicion de la bala
    balas.push_back(newBala);//agregar nueva bala
}
//mueve las balas
void Disparar::mover() {
    for(size_t i = 0; i <balas.size(); i++){
        balas[i].move(velocities[i]); // contiene la velocidad de la bala
        std::cout <<"- :"<<balas[i].getPosition().x<<std::endl; // actuliza la posicion de la bala
    }
}
void Disparar::dibujar(sf::RenderWindow& window) {
    for(const auto& bala : balas){
        window.draw(bala);
    }
}
