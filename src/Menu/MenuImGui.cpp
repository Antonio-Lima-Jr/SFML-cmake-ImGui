#include "MenuImGui.h"
#include <cmath>

MenuImGui::MenuImGui(sf::RenderWindow& window) : window(window) {
    ImGui::SFML::Init(window, true);
    my_tool_active = true;
    my_color[0] = 0.45f;
    my_color[1] = 0.55f;
    my_color[2] = 0.60f;
    my_color[3] = 1.00f;
}

MenuImGui::~MenuImGui() {
    ImGui::SFML::Shutdown();
}

void MenuImGui::update() {
    ImGui::SFML::Update(window, deltaClock.restart());
}

bool MenuImGui::processEvent(sf::Event& event) {
    ImGui::SFML::ProcessEvent(window, event);
    if (event.type == sf::Event::Closed) {
        window.close();
        return true;
    }
    return false;
}

void MenuImGui::render() {
    ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) {}
            if (ImGui::MenuItem("Save", "Ctrl+S")) {}
            if (ImGui::MenuItem("Close", "Ctrl+W")) {
                my_tool_active = false;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImGui::ColorEdit4("Color", my_color);

    float samples[100];
    for (int n = 0; n < 100; n++)
        samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 3.5f);
    ImGui::PlotLines("Samples", samples, 100);

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Debug");
    ImGui::BeginChild("Scrolling");
    ImGui::Text("Elapsed time : %f", deltaClock.getElapsedTime().asSeconds());
    ImGui::EndChild();
    ImGui::End();
    ImGui::SFML::Render(window);
}
