//
// Created by dev on 29/12/23.
//
#include "SFML/Graphics/RenderWindow.hpp"

#ifndef CMAKESFMLPROJECT_EVENTMANAGER_H
#define CMAKESFMLPROJECT_EVENTMANAGER_H

namespace game {

    class EventManager {
    private:
        sf::RenderWindow &mWindow;
    public:
        explicit EventManager(sf::RenderWindow &window);
        ~EventManager() = default;
        void processEvents();
    };

} // game

#endif //CMAKESFMLPROJECT_EVENTMANAGER_H
