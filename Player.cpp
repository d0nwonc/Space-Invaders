#include "../include/Player.hpp"
Player::Player()
{
    ship.setSize({40.f, 20.f});

    ship.setFillColor(sf::Color::Green);

    ship.setPosition({380.f, 540.f});

    speed = 400.f;
    lives = 5;
}

void Player::update(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        ship.move({-speed * deltaTime, 0.f});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        ship.move({speed * deltaTime, 0.f});
    }

    if (ship.getPosition().x < 0.f)
    {
        ship.setPosition({0.f, ship.getPosition().y});
    }

    if (ship.getPosition().x + ship.getSize().x > 800.f)
    {
        ship.setPosition({800.f - ship.getSize().x, ship.getPosition().y});
    }
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(ship);
}

sf::Vector2f Player::getPosition() const
{
    return ship.getPosition();
}
sf::FloatRect Player::getBounds() const
{
    return ship.getGlobalBounds();
}

int Player::getLives() const
{
    return lives;
}

void Player::loseLife()
{
    if (lives > 0)
    {
        lives--;
    }
}