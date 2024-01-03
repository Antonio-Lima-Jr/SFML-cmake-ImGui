//
// Created by dev on 29/12/23.
//

#include <iostream>
#include "ManagerUI.h"
#include "imgui-SFML.h"
#include "imgui.h"
#include <cmath>

namespace game {
    ManagerUI::ManagerUI(sf::RenderWindow &window) : mWindow(window) {
        if (!ImGui::SFML::Init(mWindow, true)) {
            std::cout << "Error: ImGui::SFML::Init(mWindow, true) failed" << std::endl;
        }
    }

    ManagerUI::~ManagerUI() {
        ImGui::SFML::Shutdown();
    }

    void ManagerUI::processEvents(const sf::Event &event) {
        ImGui::SFML::ProcessEvent(mWindow, event);
    }

    void ManagerUI::render(float *my_color, sf::Clock &deltaClock, const int &fps, float &f) {
        ImGui::SFML::Update(mWindow, deltaClock.restart());
        bool my_tool_active = true;

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
        // Edit a color stored as 4 floats
        ImGui::ColorEdit4("Color", my_color);



        // Generate samples and plot themS
        float samples[100];
        for (int n = 0; n < 100; n++)
            samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 3.5f);
        ImGui::PlotLines("Samples", samples, 100);

        // Display contents in a scrolling region
        ImGui::TextColored(ImVec4(1, 1, 0, 1), "Debug");
        ImGui::SliderFloat("float", &f, 0.f, 119.0f);
        ImGui::BeginChild("Scrolling");
        ImGui::Text("Elapsed time : %f", deltaClock.getElapsedTime().asSeconds());
        ImGui::Text("fps : %d", fps);
        ImGui::EndChild();

        ImGui::End();
//          move sin wave to circle

        ImGui::SFML::Render(mWindow);
    }

} // game