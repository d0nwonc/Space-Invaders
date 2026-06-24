#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

int main() {
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Space Invaders"
    );

    Player player;

    std::vector<Bullet> bullets;
    std::vector<Bullet> enemyBullets;
    std::vector<Enemy> enemies;

    // Create enemy formation
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            enemies.emplace_back(
                100.f + static_cast<float>(col) * 60.f,
                50.f + static_cast<float>(row) * 40.f
            );
        }
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    float enemyDirection = 1.f;
    int score = 0;
    int level = 1;
    bool gameOver = false;
    bool victory = false;

    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime =
            clock.restart().asSeconds();

        if (victory)
        {
            window.setTitle("YOU WIN! Press R to Restart");
        }
        else if (gameOver)
        {
            window.setTitle("GAME OVER! Press R to Restart");
        }
        else
        {
            window.setTitle(
                "Space Invaders | Level: " + std::to_string(level) +
                " | Lives: " +
                std::to_string(player.getLives()) +
                " | Score: " +
                std::to_string(score)
            );
        }

        while (const auto event =
                   window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (event->is<sf::Event::KeyPressed>())
            {
                auto* keyPressed = event->getIf<sf::Event::KeyPressed>();

                if ((gameOver || victory) &&
                    keyPressed &&
                    keyPressed->code == sf::Keyboard::Key::R)
                {
                    player = Player();
                    bullets.clear();
                    enemyBullets.clear();
                    enemies.clear();

                    for (int row = 0; row < 4; row++)
                    {
                        for (int col = 0; col < 8; col++)
                        {
                            enemies.emplace_back(
                                100.f + static_cast<float>(col) * 60.f,
                                50.f + static_cast<float>(row) * 40.f
                            );
                        }
                    }

                    score = 0;
                    level = 1;
                    enemyDirection = 1.f;
                    gameOver = false;
                    victory = false;
                }
            }

            if (event->is<sf::Event::KeyPressed>())
            {
                auto* keyPressed =
                    event->getIf<sf::Event::KeyPressed>();

                if (
                    keyPressed &&
                    keyPressed->code ==
                        sf::Keyboard::Key::Space
                )
                {
                    bullets.emplace_back(
                        player.getPosition().x + 18.f,
                        player.getPosition().y,
                        -600.f
                    );
                }
            }
        }

        player.update(deltaTime);

        bool hitEdge = false;

        for (auto& enemy : enemies)
        {
            if (enemy.isAlive())
            {
                float enemySpeed = 60.f;
                enemy.move(
                    enemyDirection *
                    enemySpeed *
                    deltaTime
                );

                auto bounds = enemy.getBounds();

                if (bounds.position.x <= 0 ||
                    bounds.position.x + bounds.size.x >= 800)
                {
                    hitEdge = true;
                }
            }
        }

        if (hitEdge)
        {
            enemyDirection *= -1.f;

            for (auto& enemy : enemies)
            {
                if (enemy.isAlive())
                {
                enemy.moveDown(5.f);
                }
            }
        }

        if (!victory &&
            !gameOver &&
            !enemies.empty() &&
            std::rand() % 2000 < 1)
        {
            int index = std::rand() % enemies.size();

            if (enemies[index].isAlive())
            {
                enemyBullets.emplace_back(
                    enemies[index].getBounds().position.x + 15.f,
                    enemies[index].getBounds().position.y + 20.f,
                    300.f
                );
            }
        }

        for (auto& bullet : bullets)
        {
            bullet.update(deltaTime);
        }

        for (auto& bullet : enemyBullets)
        {
            bullet.update(deltaTime);
        }

        // Bullet vs Enemy Collision
        for (auto& bullet : bullets)
        {
            for (auto& enemy : enemies)
            {
                if (
                    bullet.isAlive() &&
                    enemy.isAlive() &&
                    bullet.getBounds().findIntersection(
                        enemy.getBounds()
                    )
                )
                {
                    bullet.destroy();
                    enemy.destroy();
                    score += 100;
                }
            }
        }

        // Enemy Bullet vs Player Collision
        for (auto& bullet : enemyBullets)
        {
            if (
                bullet.isAlive() &&
                bullet.getBounds().findIntersection(
                    player.getBounds()
                )
            )
            {
                bullet.destroy();
                player.loseLife();
            }
        }

        if (player.getLives() <= 0)
        {
            gameOver = true;
        }

        bool allEnemiesDead = true;

        for (auto& enemy : enemies)
        {
            if (enemy.isAlive())
            {
                allEnemiesDead = false;
                break;
            }
        }

        if (allEnemiesDead && !gameOver && !victory)
        {
            if (level >= 4)
            {
                victory = true;
                enemies.clear();
                bullets.clear();
                enemyBullets.clear();
            }

            if (!victory)
            {
                level++;

                enemies.clear();
                bullets.clear();
                enemyBullets.clear();

                for (int row = 0; row < 4; row++)
                {
                    for (int col = 0; col < 8; col++)
                    {
                        enemies.emplace_back(
                            100.f + static_cast<float>(col) * 60.f,
                            50.f + static_cast<float>(row) * 40.f
                        );
                    }
                }

                enemyDirection = 1.f;
            }
        }

        window.clear();

        player.draw(window);

        for (auto& bullet : bullets)
        {
            if (bullet.isAlive())
            {
                bullet.draw(window);
            }
        }

        for (auto& bullet : enemyBullets)
        {
            if (bullet.isAlive())
            {
                bullet.draw(window);
            }
        }

        for (auto& enemy : enemies)
        {
            if (enemy.isAlive())
            {
                enemy.draw(window);
            }
        }

        window.display();
    }

    return 0;
}