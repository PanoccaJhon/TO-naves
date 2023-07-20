#ifndef PARTIDA_H
#define PARTIDA_H
#include "avion.h"
#include "ovni.h"
#include <vector>
#include <SFML/Graphics.hpp>
class Partida
{
public:
    Partida();
    void configurar();
    int enJuego();

private:
    sf::RenderWindow window;
    bool estado;
    int puntaje;
    int nivel;
    //std::vector<sf::Sprite> sprites;
    Avion avion;
    Ovni emg;
    //Agregar mas cosas
};

#endif // PARTIDA_H
