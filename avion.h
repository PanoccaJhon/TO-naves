#ifndef AVION_H
#define AVION_H

#include <string>
#include <SFML/Graphics.hpp>
class Avion: public sf::Sprite
{
public:
    Avion();
    void girar(sf::Vector2i mouse);
    void avanzar(sf::Vector2i mouse);
    void disparar(sf::Vector2i mouse);
private:

    std::string image;
    sf::Texture texture;
    float velocity;


};

#endif // AVION_H
