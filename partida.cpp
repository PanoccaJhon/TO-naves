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
    window.setFramerateLimit(40);
    sprites.push_back(new Avion());
}
int Partida::enJuego()
{
    sf::Clock clockAste;
    sf::Clock clockOvni;
    while(window.isOpen())
    {
        window.clear(sf::Color(55,55,72));

        //Movimiento de Avion
        if(sprites[0]->movimiento)
            sprites[0]->avanzar();
        //Generar Asteorides
        if(clockAste.getElapsedTime().asSeconds()>1.3f){
            sprites.push_back(new Asteroide());
            sprites.back()->setObjetivo(sprites[0]->getPosition());
            clockAste.restart();
        }
        //Generar Ovnis
        if(clockOvni.getElapsedTime().asSeconds()>2.3f){
            sprites.push_back(new Ovni());
            sprites.back()->setObjetivo(sprites[0]->getPosition());
            clockOvni.restart();
        }
        //Eventos
        sf::Event event;
        while (window.pollEvent(event))
        {

            //Click mouse boton izquierdo -- MOVERSE
            if(event.type == sf::Event::MouseButtonPressed &&sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                //Girar Avion hacia click de mouse
                sprites[0]->girar(sf::Mouse::getPosition(window));
            }

            //Click tecla Space -- DISPARAR


            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Mover Meteoros y Naves enemigas
        for(auto i = 1; i<sprites.size();i++){
            sprites[i]->moverse();
        }

        //Renderizar Sprites
        for(auto item: sprites){
            window.draw(*item);
        }
        window.display();
    }
    return puntaje;
}
