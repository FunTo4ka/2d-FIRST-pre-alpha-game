#ifndef FIREBALL_H
#define FIREBALL_H

#include <SFML/Graphics.hpp>

class Fireball {
public:
    Fireball(sf::Vector2f position, sf::Vector2f direction);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isAlive() const;
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float speed;
    float lifetime;
};

#endif