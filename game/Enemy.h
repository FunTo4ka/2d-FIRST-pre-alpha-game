#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Enemy {
public:
    Enemy(sf::Vector2f position);
    void update(float deltaTime, const Player& player);
    void draw(sf::RenderWindow& window);
    bool isAlive() const;
    sf::FloatRect getBounds() const;
    void takeDamage(int damage); // Добавленный метод

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    float speed;
    int health;
};

#endif