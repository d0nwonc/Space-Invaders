#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::RectangleShape body;

    bool alive;

public:
    Enemy(float x, float y);

    void draw(sf::RenderWindow& window) const;

    sf::FloatRect getBounds() const;

    bool isAlive() const;

    void destroy();

    void move(float dx);

    void moveDown(float dy);
};