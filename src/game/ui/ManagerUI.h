//
// Created by dev on 29/12/23.
//
#include "SFML/Graphics/RenderWindow.hpp"

#ifndef CMAKESFMLPROJECT_MANAGERUI_H
#define CMAKESFMLPROJECT_MANAGERUI_H

namespace game {

    class ManagerUI {
    public:
        explicit ManagerUI(sf::RenderWindow &window);

        ~ManagerUI();

        void processEvents(const sf::Event &event);

        void render(float *my_color, sf::Clock &deltaClock, const int &fps, float &f);

    private:
        sf::RenderWindow &mWindow;
    };

} // game

#endif //CMAKESFMLPROJECT_MANAGERUI_H
