#include "partida.h"
#include "Disparar.h"
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
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(40);
    sprites.push_back(new Avion());

    //Configurar vidas
    vidas.push_back(new Vida(sf::Vector2f(50,20)));
    vidas.push_back(new Vida(sf::Vector2f(100,20)));
    vidas.push_back(new Vida(sf::Vector2f(150,20)));
    vidas.push_back(new Vida(sf::Vector2f(200,20)));
}
int Partida::enJuego()
{
    sf::Clock clockAste;
    sf::Clock clockOvni;
    sf::Clock clockOvni2;
    while(window.isOpen())
    {
        window.clear(sf::Color(55,55,72));
        //mostrar puntaje
        sf::Font font;
        if (font.loadFromFile("D:/aviones/TO-naves-main/Imagenes/28 Days Later.ttf")) {
            sf::Text puntajeText;
            puntajeText.setFont(font);
            puntajeText.setCharacterSize(24);
            puntajeText.setFillColor(sf::Color::White);

            // Ajustar las coordenadas para colocar el texto en la esquina superior derecha
            float x = window.getSize().x - 200- puntajeText.getGlobalBounds().width;
            float y = 10;
            puntajeText.setPosition(x, y);

            puntajeText.setString("Puntaje: " + std::to_string(puntaje));

            window.draw(puntajeText);
        }
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
        //Generar Ovnis2
        if(clockOvni2.getElapsedTime().asSeconds()>15.3f){
            sprites.push_back(new Ovni2());
            sprites.back()->setObjetivo(sprites[0]->getPosition());
            clockOvni2.restart();
        }
        //Eventos
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                //sprites[0]->disparar();
                disparador.disparar(sprites[0]->getPosition(), sprites[0]->getRotation());
            }

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
        disparador.mover();

        // Detección de colisiones entre las balas y los asteroides/UFOs
            const std::vector<sf::Sprite>& balas = disparador.getBalas();
        for (size_t i = 0; i < balas.size(); i++)
        {
            sf::FloatRect balaBounds = balas[i].getGlobalBounds();
            bool colision = false; // Variable para indicar si hay colisión

            // Colisión con asteroides
            for (size_t j = 1; j < sprites.size(); j++)
            {
                sf::FloatRect asteroideBounds = sprites[j]->getGlobalBounds();
                if (balaBounds.intersects(asteroideBounds))
                {
                   
                    colision = true;
                    puntaje += 10;
                    sprites.erase(sprites.begin() + j);
                    break; // Exit the inner loop since the bullet can't hit multiple objects at once
                }
            }

            if (colision)
            {
                disparador.marcarBalaEliminada(i);
            }
        }

         // Detección de colisiones entre el avión y los asteroides/UFOs
        sf::FloatRect avionBounds = sprites[0]->getGlobalBounds();
        for (size_t i = 1; i < sprites.size(); i++)
        {
            sf::FloatRect objetoBounds = sprites[i]->getGlobalBounds();
            if (avionBounds.intersects(objetoBounds))
            {
                // Colisión entre el avión y el objeto (asteroide/uFO)
                // Restar una vida y eliminar el corazón correspondiente
                sprites[0]->vidas--;
                vidas[sprites[0]->vidas]->reducirVida();

                // Eliminar el asteroide/uFO
                sprites.erase(sprites.begin() + i);

                // Si el avión se queda sin vidas, terminar el juego
                if (sprites[0]->vidas == 0)
                {
                    std::cout << "Game Over" << std::endl;
                    window.close();
                }

                break; // Salir del bucle, ya que el avión no puede colisionar con múltiples objetos al mismo tiempo
            }
        }

        // ...

        //Renderizar vidas
        for (auto i = 0; i < sprites[0]->getVidas(); i++)
        {
            if (vidas[i]->estaViva())
            {
                window.draw(*vidas[i]);
            }
        }

        disparador.dibujar(window); //Dibujas misiles
        //Mover Meteoros y Naves enemigas
        for(auto i = 1; i<sprites.size();i++){
            sprites[i]->moverse();
        }
        //Renderizar Sprites
        for(auto item: sprites){
            window.draw(*item);
        }

        //Renderizar vidas
        for(auto i = 0; i<sprites[0]->getVidas();i++){
            window.draw(*vidas[i]);
        }
        window.display();
    }
    return puntaje;
}
