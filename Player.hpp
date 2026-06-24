#pragma once

#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::RectangleShape ship;
    float speed;
    int lives;

public:
    Player();

    void update(float deltaTime);

    void draw(sf::RenderWindow& window) const;

    sf::Vector2f getPosition() const;

    sf::FloatRect getBounds() const;

    int getLives() const;

    void loseLife();
};