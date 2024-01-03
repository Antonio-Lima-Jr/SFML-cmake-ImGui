//
// Created by dev on 28/12/23.
//

#ifndef CMAKESFMLPROJECT_WORLD_H
#define CMAKESFMLPROJECT_WORLD_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "ui/ManagerUI.h"
#include "utils/EventManager.h"

namespace game {

    class World {
    public:
        World();
        ~World();
        void render();
        void setup();
    private:
        sf::RenderWindow mWindow;
        sf::Clock deltaClock;
        game::ManagerUI m_managerUI;
        game::EventManager m_eventManager;
        sf::Vector2<unsigned int > _centerScreen;
    };

} // game

#endif //CMAKESFMLPROJECT_WORLD_H
