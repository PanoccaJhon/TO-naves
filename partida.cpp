#include "partida.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
Partida::Partida()
{
    window.create(sf::VideoMode(1024, 768), "My window");
}

void Partida::configurar()
{
    this->estado = true;
    this->puntaje = 13;
    this->nivel = 1;
    window.setFramerateLimit(80);
    Avion avion;
}
int Partida::enJuego()
{
    while(window.isOpen())
    {
        window.clear(sf::Color(55,55,72));

        if(avion.movimiento)
            avion.avanzar();

        sf::Event event;
        while (window.pollEvent(event))
        {


            //Click mouse boton izquierdo
            if(event.type == sf::Event::MouseButtonPressed &&sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                //Girar Avion hacia click de mouse
                avion.girar(sf::Mouse::getPosition(window));
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(avion);
        window.display();
    }
    return puntaje;
}
