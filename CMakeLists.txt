cmake_minimum_required(VERSION 3.28)

project(UCF_FIEA)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "/opt/homebrew/opt/sfml/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

include_directories(include)

add_executable(
        UCF_FIEA

        main.cpp
        src/Player.cpp
        src/Bullet.cpp
        src/Enemy.cpp
)

target_link_libraries(UCF_FIEA
        SFML::Graphics
        SFML::Window
        SFML::System
)