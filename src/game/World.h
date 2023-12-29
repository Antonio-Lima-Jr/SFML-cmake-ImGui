//
// Created by dev on 28/12/23.
//

#ifndef CMAKESFMLPROJECT_WORLD_H
#define CMAKESFMLPROJECT_WORLD_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "GridSingleton.h"
#include "GridSingleton_v2.h"

namespace game {

    class World {
    public:
        World();
        ~World();

        void update();
        void render();
    private:
        sf::RenderWindow mWindow;
        sf::Clock deltaClock;
        game::GridSingleton_v2 m_grid;
        static void initGrid() ;
    };

} // game

#endif //CMAKESFMLPROJECT_WORLD_H
