#include "Fireball.h"

Fireball::Fireball(sf::Vector2f position, sf::Vector2f direction) {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(position);
    speed = 300.f;
    velocity = direction * speed;
    lifetime = 2.f; // Время жизни огненного шара
}

void Fireball::update(float deltaTime) {
    shape.move(velocity * deltaTime);
    lifetime -= deltaTime;
}

void Fireball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Fireball::isAlive() const {
    return lifetime > 0;
}

sf::FloatRect Fireball::getBounds() const {
    return shape.getGlobalBounds();
}