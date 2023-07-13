#ifndef PARTIDA_H
#define PARTIDA_H

#include <SFML/Graphics.hpp>
class Partida
{
public:
    Partida();

private:
    sf::RenderWindow window;
    bool estado;
    int puntaje;
    int nivel;

};

#endif // PARTIDA_H
