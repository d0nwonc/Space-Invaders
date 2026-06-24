#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::RectangleShape shape;

    float speed;

    bool alive;

public:
    Bullet(
        float x,
        float y,
        float speed
    );

    void update(float deltaTime);

    void draw(sf::RenderWindow& window) const;

    bool isAlive() const;

    sf::FloatRect getBounds() const;

    auto destroy() -> void;
};