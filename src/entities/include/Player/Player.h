#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void handleInput();
    sf::Vector2f getPosition() const;
    void takeDamage(int damage);

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    float speed;
    int health;
};

#endif