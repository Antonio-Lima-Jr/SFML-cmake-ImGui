//
// Created by dev on 28/12/23.
//

#ifndef CMAKESFMLPROJECT_GRIDSINGLETON_H
#define CMAKESFMLPROJECT_GRIDSINGLETON_H

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

namespace game {
    struct Grid {
        sf::RectangleShape shape;
    };

    class GridSingleton {
    private:
        static GridSingleton *instance;
        Grid grid[120][120];
    protected:
        GridSingleton();

        ~GridSingleton() = default;

    public:
        GridSingleton(GridSingleton &other) = delete;

        void operator=(const GridSingleton &) = delete;

        static GridSingleton *getInstance();

        void initGrid();

        std::vector<std::vector<Grid>> getGrid();

//        getGrid

    };

} // game

#endif //CMAKESFMLPROJECT_GRIDSINGLETON_H
