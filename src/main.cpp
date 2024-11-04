#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <cmath>
#include <iostream>

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    void init();
    void processEvents();
    void update();
    void render();
    void handleGUI();

    sf::RenderWindow window;
    sf::Clock deltaClock;
    bool my_tool_active;
    float my_color[4];
};

Game::Game()
    : window(sf::VideoMode(1800, 800), "My Juego"), my_tool_active(true)
{
    window.setFramerateLimit(144);
    if (!ImGui::SFML::Init(window, true)) {
        throw std::runtime_error("Failed to initialize ImGui-SFML");
    }
}

Game::~Game() {
    ImGui::SFML::Shutdown();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(window, event);
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
    ImGui::SFML::Update(window, deltaClock.restart());
}

void Game::render() {
    window.clear();
    handleGUI();
    ImGui::SFML::Render(window);
    window.display();
}

void Game::handleGUI() {
    ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
            if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
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
}

int main() {
    try {
        Game game;
        game.run();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
