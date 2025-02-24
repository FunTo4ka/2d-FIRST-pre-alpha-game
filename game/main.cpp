#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Player.h"
#include "Enemy.h"
#include "Fireball.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Top-Down Game");
    window.setFramerateLimit(60);

    Player player;
    std::vector<Enemy> enemies;
    std::vector<Fireball> fireballs;

    // Создаём врагов
    for (int i = 0; i < 5; ++i) {
        enemies.emplace_back(sf::Vector2f(rand() % 800, rand() % 600));
    }

    sf::Clock clock;
    sf::Clock fireballCooldown;
    float cooldownTime = 0.5f; // Задержка между вызовами огненных шаров

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Управление игроком
        player.handleInput();

        // Вызов огненного шара
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if (fireballCooldown.getElapsedTime().asSeconds() >= cooldownTime) {
                fireballs.emplace_back(player.getPosition(), sf::Vector2f(1.f, 0.f));
                fireballCooldown.restart();
            }
        }

        // Обновление игрока
        player.update(deltaTime);

        // Обновление врагов
        for (auto& enemy : enemies) {
            enemy.update(deltaTime, player);
        }

        // Обновление огненных шаров
        for (auto& fireball : fireballs) {
            fireball.update(deltaTime);
        }

        // Проверка столкновений огненных шаров с врагами
        for (auto& fireball : fireballs) {
            for (auto& enemy : enemies) {
                if (fireball.getBounds().intersects(enemy.getBounds())) {
                    enemy.takeDamage(10); // Наносим урон врагу
                }
            }
        }

        // Очистка мёртвых огненных шаров и врагов
        fireballs.erase(std::remove_if(fireballs.begin(), fireballs.end(),
            [](const Fireball& f) { return !f.isAlive(); }), fireballs.end());

        enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
            [](const Enemy& e) { return !e.isAlive(); }), enemies.end());

        // Отрисовка
        window.clear();
        player.draw(window);
        for (auto& enemy : enemies) {
            enemy.draw(window);
        }
        for (auto& fireball : fireballs) {
            fireball.draw(window);
        }
        window.display();
    }

    return 0;
}