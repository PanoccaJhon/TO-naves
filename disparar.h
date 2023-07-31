#ifndef DISPARAR_H
#define DISPARAR_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>


class Disparar
{
private:

    sf::Texture texture_bala;
    sf::Sprite bala;
    //sf::Vector2f velocity;
    sf::Keyboard::Key tecla;
    std::vector<sf::Sprite> balas;
    std::vector<sf::Vector2f> velocities;
    std::vector<size_t> balasEliminadas;

public:
    //constructores
    Disparar(sf::Keyboard::Key teclado);
    Disparar();

    //metodos
    sf::Vector2f getDirectionVector(float angle);
    void disparar(sf::Vector2f posicion, float angle);
    void mover();
    void dibujar(sf::RenderWindow& window);
    const std::vector<sf::Sprite>& getBalas() const;
    void eliminarBala(size_t indice);
    void marcarBalaEliminada(size_t indice);
    void eliminarBalasMarcadas();
};

#endif // DISPARAR_H
