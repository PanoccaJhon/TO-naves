#ifndef PARTIDA_H
#define PARTIDA_H
#include "avion.h"

#include <SFML/Graphics.hpp>
class Partida
{
public:
    Partida();
    void configurar();
    void enJuego();

private:
    sf::RenderWindow window;
    bool estado;
    int puntaje;
    int nivel;
    Avion avion;
    //Agregar mas cosas
};

#endif // PARTIDA_H
