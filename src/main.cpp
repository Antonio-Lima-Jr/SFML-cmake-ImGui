#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <cmath>
#include "Menu/MenuImGui.h"

int main()
{
    unsigned int winX = 1500;
    unsigned int winY = 900;
    float cX = winX / 2;
    float cY = winY / 2;
    float R = M_PI * 100;
    float r = M_PI * 30;
    float dT = M_PI / 100.;
    float theta = 0.;
    float Theta = 0.;

    int 	width, tempx, tempy, counter, red, green, blue;

    width = 2;

    float d = 50;
    float X, Y, x, y ; 

    std::string sign = "m";

    auto window = sf::RenderWindow{{winX, winY}, "My Juego"};
    window.setFramerateLimit(144);
    MenuImGui menuImGui = MenuImGui(window);

    sf::Clock deltaClock;

    sf::Texture texture;
    texture.create(winX, winY);

    sf::Uint8 *pixels = new sf::Uint8[winX * winY * 4];
    for (int i = 0; i < winX * winY * 4; i += 4)
    {
        pixels[i] = 210;
        pixels[i + 1] = 200;
        pixels[i + 2] = 150;
        pixels[i + 3] = 255;
    }
    sf::Sprite sprite(texture);

    bool my_tool_active = true;
    float my_color[4];

    while (window.isOpen())
    {
        menuImGui.update();

        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            menuImGui.processEvent(event);
            if (event.type == sf::Event::Closed)
            {
                window.close();
                ImGui::SFML::Shutdown();
            }
        }

        window.clear();

        Theta += dT;

        if (sign == "m")
            theta -= dT * 2 * R / d;
        if (sign == "p")
            theta += dT * 2 * R / d;

        X = cX + R * cos(Theta);
        Y = cY + R * sin(Theta);

        x = X + r * cos(theta);
        y = Y + r * sin(theta);

        tempx = int(x);
        tempy = int(y);

        counter = 0;

        // Change the pixel colors at the pencil location (and nearby locations to accomodate the requested 'stroke width') to the color specified by the user.
        while (counter < width)
        {
            if ((4 * tempy * winX + 4 * (tempx + counter - int(0.5 * counter))) < winX * winY * 4)
            {
                pixels[4 * tempy * winX + 4 * (tempx + counter - int(0.5 * counter)) + 0] = 155;
                pixels[4 * tempy * winX + 4 * (tempx + counter - int(0.5 * counter)) + 1] = 100;
                pixels[4 * tempy * winX + 4 * (tempx + counter - int(0.5 * counter)) + 2] = 200;
            }
            counter++;
        }
        
        window.draw(sprite);
        texture.update(pixels);
        menuImGui.render();
        window.display();
    }
}