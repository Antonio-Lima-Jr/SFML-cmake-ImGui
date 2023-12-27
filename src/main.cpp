#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <imgui-SFML.h>
#include <imgui.h>
#include <cmath>

int main()
{
    auto window = sf::RenderWindow{{1800u, 800u}, "CMake SFML Project"};
    window.setFramerateLimit(144);
    if (!ImGui::SFML::Init(window, true))
    {
        return 0;
    }
    

    sf::Clock deltaClock;

    bool my_tool_active = true;
    float my_color[4];

    while (window.isOpen())
    {
        ImGui::SFML::Update(window, deltaClock.restart());

        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type == sf::Event::Closed)
            {
                window.close();
                ImGui::SFML::Shutdown();
            }
        }

        // ImGui::ShowDemoWindow();
        ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Open..", "Ctrl+O"))
                { /* Do stuff */
                }
                if (ImGui::MenuItem("Save", "Ctrl+S"))
                { /* Do stuff */
                }
                if (ImGui::MenuItem("Close", "Ctrl+W"))
                {
                    my_tool_active = false;
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        // Edit a color stored as 4 floats
        ImGui::ColorEdit4("Color", (float*)&my_color);



        // Generate samples and plot themS
        float samples[100];
        for (int n = 0; n < 100; n++)
            samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 3.5f);
        ImGui::PlotLines("Samples", samples, 100);

        // Display contents in a scrolling region
        ImGui::TextColored(ImVec4(1, 1, 0, 1), "Debug");
        ImGui::BeginChild("Scrolling");
     
        ImGui::Text("Elapsed time : %f", deltaClock.getElapsedTime().asSeconds());
        ImGui::EndChild();
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }
}