#include "partida.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Partida::Partida()
{
    window.create(sf::VideoMode(1024, 768), "My window");
}

void Partida::configurar()
{
    this->estado = true;
    this->puntaje = 13;
    this->nivel = 1;
    Avion avion;
}
int Partida::enJuego()
{
    while(window.isOpen())
    {
        window.clear(sf::Color(55,55,72));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::MouseButtonPressed &&sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                avion.girar(sf::Mouse::getPosition(window));
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(avion);
        window.display();
    }
}
