#ifndef AVION_H
#define AVION_H

#include <string>
#include <SFML/Graphics.hpp>
class Avion: public sf::Sprite
{
public:
    Avion();
    void girar(sf::Vector2i mouse);
    void avanzar(sf::Vector2i &mouse);
    void disparar();
private:

    std::string image;
    sf::Texture texture;
    sf::Sprite sprite;
    float velocity;


};

#endif // AVION_H
