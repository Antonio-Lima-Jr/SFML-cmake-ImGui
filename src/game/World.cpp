//
// Created by dev on 28/12/23.
//

#include <iostream>
#include "World.h"
#include "imgui.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include <chrono>
#include <cmath>

namespace game {
    World::World() : mWindow(sf::VideoMode(),
                             "CMake SFML Project",
                             sf::Style::Fullscreen),
                     deltaClock(),
                     m_managerUI(mWindow),
                     m_eventManager(mWindow),
                     _centerScreen({mWindow.getSize().x / 2, mWindow.getSize().y / 2}) {
        std::cout << "World created" << std::endl;
    }

    void World::setup() {
        mWindow.setFramerateLimit(160);
        auto size = mWindow.getSize();
        auto centerScreen = sf::Vector2f(size.x / 2, size.y / 2);
    }

    void World::render() {
        std::chrono::high_resolution_clock::time_point start;
        std::chrono::high_resolution_clock::time_point end;

        float my_color[4];
        float fps;
        float f = 110.0f;
        float currentTime = 0;
        sf::Time time;
        sf::Clock clock;

        auto circle = new sf::CircleShape(2);
        circle->setFillColor(sf::Color::Red);


        circle->setPosition((float) _centerScreen.x, (float) _centerScreen.y);
        while (mWindow.isOpen()) {
            start = std::chrono::high_resolution_clock::now();
//            transforme start em um float

            m_eventManager.processEvents();
            mWindow.clear();
            m_managerUI.render(my_color, deltaClock, fps, f);

            sf::Vector2<float> positionRotate;
            positionRotate.x = _centerScreen.x + 100 * cosf(currentTime / 100000.0f);
            positionRotate.y = _centerScreen.y + 100 * sinf(currentTime / 100000.0f);

            auto secondRotante=(sf::Vector2<float>) {positionRotate.x - _centerScreen.x * cosf(currentTime / 1000000.0f), positionRotate.y - _centerScreen.y * sinf(currentTime / 1000000.0f)};
//            std::cout << "Time: " << time.asMilliseconds() << "Delta Clock: " <<  << std::endl;
//        use as funçoes de seno e cosseno para fazer o circulo girar
            currentTime += clock.getElapsedTime().asSeconds();
            circle->setPosition(
                    secondRotante.x,
                    secondRotante.y
            );
            mWindow.draw(*circle);
            mWindow.display();
            end = std::chrono::high_resolution_clock::now();
            fps = (float) 1e9 / (float) std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        }
    }

    World::~World() {
        std::cout << "World destroyed" << std::endl;
    }
} // game