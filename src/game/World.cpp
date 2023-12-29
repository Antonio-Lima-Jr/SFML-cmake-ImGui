//
// Created by dev on 28/12/23.
//

#include <iostream>
#include "World.h"
#include "imgui-SFML.h"
#include "imgui.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "GridSingleton.h"
#include <cmath>
#include <chrono>

namespace game {

    World::World() : mWindow(sf::VideoMode(1800u, 800u),
                             "CMake SFML Project"),
                     deltaClock(),
                     m_grid( GridSingleton_v2::getInstance(100, 100)){
//        initGrid();
        std::cout << "World created" << std::endl;
    }

    void World::update() {

    }

    void World::render() {
        mWindow.setFramerateLimit(160);
        if (!ImGui::SFML::Init(mWindow, true)) {
            return;
        }

        bool my_tool_active = true;
        float my_color[4];

        std::chrono::high_resolution_clock::time_point start;
        std::chrono::high_resolution_clock::time_point end;
        float fps;
        float f = 0.0f;
        auto circle = new sf::CircleShape(10);

        circle->setFillColor(sf::Color::Red);
        circle->setPosition(400, 100);
        while (mWindow.isOpen()) {
            start = std::chrono::high_resolution_clock::now();
            ImGui::SFML::Update(mWindow, deltaClock.restart());

            for (auto event = sf::Event{}; mWindow.pollEvent(event);) {
                ImGui::SFML::ProcessEvent(mWindow, event);
                if (event.type == sf::Event::Closed) {
                    mWindow.close();
                    ImGui::SFML::Shutdown();
                }
            }

            // ImGui::ShowDemoWindow();
            ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
            if (ImGui::BeginMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */
                    }
                    if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */
                    }
                    if (ImGui::MenuItem("Close", "Ctrl+W")) {
                        my_tool_active = false;
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }
            mWindow.clear();
            // Edit a color stored as 4 floats
            ImGui::ColorEdit4("Color", (float *) &my_color);



            // Generate samples and plot themS
            float samples[100];
            for (int n = 0; n < 100; n++)
                samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 3.5f);
            ImGui::PlotLines("Samples", samples, 100);

            // Display contents in a scrolling region
            ImGui::TextColored(ImVec4(1, 1, 0, 1), "Debug");
            ImGui::SliderFloat("float", &f, -500.0f, 500.0f);
            ImGui::BeginChild("Scrolling");

            ImGui::Text("Elapsed time : %f", deltaClock.getElapsedTime().asSeconds());
            ImGui::Text("fps : %f", fps);
            ImGui::EndChild();

            ImGui::End();
//          move sin wave to circle
            circle->setPosition(circle->getPosition().x, 200 + sinf(ImGui::GetTime() * 3.5f) * 100);
            mWindow.draw(*circle);

            ImGui::SFML::Render(mWindow);

            
//            draw grid
            for(auto i : m_grid.)
//             for (int i = 0; i < my_grid.size(); i++) {
//                 for (int j = 0; j < 120; j++) {
//                     my_grid[i][j].shape.setPosition(my_grid[i][j].shape.getPosition().x + f, my_grid[i][j].shape.getPosition().y);
//                     mWindow.draw(my_grid[i][j].shape);
//                 }
//             }

//            for (int i = 0; i < 50; i++) {
//                for (int j = 0; j < 50; ++j) {
//                    auto my_grid = m_grid->getGrid();
//                    mWindow.draw(my_grid[i][j].shape);
//                    mWindow.draw(m_grid->getGrid()[i][j].shape);
//                }
//            }

            mWindow.display();
            end = std::chrono::high_resolution_clock::now();
            fps = (float)1e9/(float)std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        }
    }

    World::~World() {
        std::cout << "World destroyed" << std::endl;
    }


    void World::initGrid() {
//        const int offset = 400;
//        for (int i = 0; i < 120; i++) {
//            for (int j = 0; j < 120; j++) {
//                m_grid->getGrid()[i][j].shape = sf::RectangleShape(sf::Vector2f(10, 10));
//                m_grid->getGrid()[i][j].shape.setPosition(sf::Vector2f(i * 10 + offset, j * 10));
//                m_grid->getGrid()[i][j].shape.setFillColor(sf::Color::White);
//            }
//        }

    }
} // game