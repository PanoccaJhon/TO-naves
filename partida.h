#ifndef PARTIDA_H
#define PARTIDA_H
#include "avion.h"
#include "Disparar.h"
#include "ovni.h"
#include "asteroide.h"
#include "mysprite.h"
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
    Asteroide aste;
    std::vector<MySprite*> sprites;
    //Agregar mas cosas
    Disparar disparador;
};

#endif // PARTIDA_H
