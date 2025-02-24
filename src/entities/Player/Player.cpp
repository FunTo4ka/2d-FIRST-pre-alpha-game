#include "Player.h"

Player::Player() {
    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(400.f, 300.f);
    speed = 200.f;
    health = 100;
}

void Player::update(float deltaTime) {
    shape.move(velocity * deltaTime);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Player::handleInput() {
    velocity = sf::Vector2f(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        velocity.y = -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        velocity.y = speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x = -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x = speed;
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}