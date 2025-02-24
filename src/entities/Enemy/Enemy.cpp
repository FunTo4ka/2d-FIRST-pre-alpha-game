#include "Enemy.h"
#include <cmath>

Enemy::Enemy(sf::Vector2f position) {
    shape.setSize(sf::Vector2f(40.f, 40.f));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
    speed = 100.f;
    health = 50;
}

void Enemy::update(float deltaTime, const Player& player) {
    sf::Vector2f direction = player.getPosition() - shape.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) direction /= length;

    velocity = direction * speed;
    shape.move(velocity * deltaTime);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Enemy::isAlive() const {
    return health > 0;
}

sf::FloatRect Enemy::getBounds() const {
    return shape.getGlobalBounds();
}

void Enemy::takeDamage(int damage) { // Реализация метода takeDamage
    health -= damage;
    if (health < 0) health = 0;
}