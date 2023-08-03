#ifndef PARTIDA_H
#define PARTIDA_H
#include "avion.h"
#include "Disparar.h"
#include "ovni.h"
#include "ovni2.h"
#include "asteroide.h"
#include "mysprite.h"
#include "vida.h"
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
    Ovni2 infoemg;
    Asteroide aste;
    std::vector<MySprite*> sprites;
    //Agregar mas cosas
    Disparar disparador;
    std::vector<Vida*> vidas;
    sf::Font font;
    sf::Text puntajeText;
    sf::Text gameOverText; // Texto para mostrar "Game Over"
    bool gameOver; // Variable para indicar si el juego ha terminado
};

#endif // PARTIDA_H
