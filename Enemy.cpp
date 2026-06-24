#include "../include/Enemy.hpp"

Enemy::Enemy(float x, float y)
{
    alive = true;

    body.setSize({30.f, 20.f});

    body.setFillColor(sf::Color::White);

    body.setPosition({x, y});
}

void Enemy::draw(sf::RenderWindow& window) const {
    if (alive)
    {
        window.draw(body);
    }
}

sf::FloatRect Enemy::getBounds() const
{
    return body.getGlobalBounds();
}

bool Enemy::isAlive() const
{
    return alive;
}

void Enemy::destroy() {
    alive = false;
}
    void Enemy::move(float dx)
    {
        body.move({dx, 0.f});
    }
    void Enemy::moveDown(float dy)
    {
        body.move({0.f, dy});
    }