//
// Created by dev on 28/12/23.
//

#include "GridSingleton.h"

namespace game {
    GridSingleton *GridSingleton::instance = nullptr;

    GridSingleton::GridSingleton(): grid() {
        initGrid();
    }

    GridSingleton *GridSingleton::getInstance() {
        if (!instance) {
            instance = new GridSingleton();
        }
        return instance;
    }

    void GridSingleton::initGrid() {
        int offset = 400;
        for (int i = 0; i < 120; i++) {
            for (int j = 0; j < 120; j++) {
                grid[i][j].shape = sf::RectangleShape(sf::Vector2f(5, 5));
                grid[i][j].shape.setFillColor(sf::Color::Black);
                grid[i][j].shape.setOutlineColor(sf::Color::White);
                grid[i][j].shape.setOutlineThickness(1);

//

                grid[i][j].shape.setPosition(offset+(i * 5), offset/3+(j * 5));
            }
        }
    }

    std::vector<std::vector<Grid>> GridSingleton::getGrid() {
        std::vector<std::vector<Grid>> gridVector;
        for (int i = 0; i < 120; i++) {
            std::vector<Grid> row;
            for (int j = 0; j < 120; j++) {
                row.push_back(grid[i][j]);
            }
            gridVector.push_back(row);
        }
        return gridVector;
    }

//    Grid GridSingleton::getGrid() {
//        return grid[0][0];
//    }


} // game