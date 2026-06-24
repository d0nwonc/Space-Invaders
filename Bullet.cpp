#include "../include/Bullet.hpp"

Bullet::Bullet(
    float x,
    float y,
    float speed
)
{
    this->speed = speed;

    alive = true;

    shape.setSize({4.f, 12.f});

    shape.setFillColor(
        sf::Color::Red
    );

    shape.setPosition({x, y});
}

void Bullet::update(
    float deltaTime
)
{
    shape.move(
        {0.f, speed * deltaTime}
    );

    if (
        shape.getPosition().y < -20
    )
    {
        alive = false;
    }
}

void Bullet::draw(
    sf::RenderWindow& window
) const {
    window.draw(shape);
}

bool Bullet::isAlive() const
{
    return alive;
}

void Bullet::destroy()
{
    alive = false;
}

sf::FloatRect Bullet::getBounds() const
{
    return shape.getGlobalBounds();
}