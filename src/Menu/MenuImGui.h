#ifndef MENUIMGUI_H
#define MENUIMGUI_H

#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

class MenuImGui {
public:
    MenuImGui(sf::RenderWindow& window);
    ~MenuImGui();

    void update();
    bool processEvent(sf::Event& event);
    void render();

private:
    sf::RenderWindow& window;
    sf::Clock deltaClock;
    bool my_tool_active;
    float my_color[4];
};

#endif // MENUIMGUI_H
