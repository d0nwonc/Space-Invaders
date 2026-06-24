# Space Invaders

## Overview

Space Invaders is a 2D arcade-style shooter developed in C++ using SFML. The goal of the game is to eliminate enemy ships, survive incoming attacks, and progress through multiple levels. As the player advances, the enemies become more challenging and the game continues until the player either wins or loses all of their lives.

This was one of my first larger game projects in C++, and I wanted to challenge myself by recreating a classic arcade game while learning more about game development, object-oriented programming, collision detection, and game loops.

## Features

- Player-controlled spaceship
- Enemy formations
- Multiple levels
- Projectile system
- Enemy projectile system
- Collision detection
- Score tracking
- Lives system
- Game over screen
- Victory screen
- Restart functionality

## Controls

- Left Arrow – Move Left
- Right Arrow – Move Right
- Space Bar – Shoot
- R – Restart after Game Over or Victory

## Technologies Used

- C++
- SFML 3
- Object-Oriented Programming
- Collision Detection
- Vectors and Dynamic Collections
- Game Loops
- State-Based Gameplay Logic

## What I Learned

This project helped me get more comfortable building larger programs in C++ and organizing code into multiple classes. I learned how to manage enemies, bullets, player health, scoring systems, and level progression while keeping everything working together. I also gained experience using vectors, handling collisions between game objects, and creating a complete gameplay loop from start to finish.

One of the biggest things I learned was how different game systems depend on each other. It wasn't just about making the player move or making enemies appear. I had to make sure the player, enemies, bullets, scoring system, lives system, and level progression all worked together correctly.

One thing that made this project interesting was that I had previously worked on a similar game concept in Python. Rebuilding a game like this in C++ gave me a better understanding of object-oriented programming and how game systems are structured in a lower-level language. It also gave me a chance to compare the differences between developing games in Python and C++, especially when it came to project organization, performance, and working with libraries like SFML.

## Future Improvements

If I continue developing this project, there are several features I would like to add:

- More enemy formations and attack patterns
- Boss battles at the end of certain levels
- Power-ups such as rapid fire, shields, or extra lives
- Different enemy types with unique behaviors
- Improved visual effects and animations
- Sound effects and background music
- A main menu and settings screen
- High score tracking and score saving

My main focus for this version was building the core gameplay systems and making sure the game loop, level progression, scoring, and combat mechanics worked reliably. Future updates would focus on adding more content, difficulty variety, and overall polish.

## Development Notes

I built this project myself using C++ and SFML. I created the player controls, enemy system, projectile mechanics, scoring system, lives system, level progression, and overall game flow. During development, I also used AI as a learning tool when I got stuck or wanted help understanding different approaches to solving a problem. I still reviewed, tested, modified, and integrated the code myself throughout development. The final project reflects my own understanding of how the game works.

## Project Structure

```text
include/
├── Player.hpp
├── Enemy.hpp
├── Bullet.hpp

src/
├── Player.cpp
├── Enemy.cpp
├── Bullet.cpp

main.cpp
CMakeLists.txt
```
