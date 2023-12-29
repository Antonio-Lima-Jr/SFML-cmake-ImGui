//
// Created by certi on 12/29/23.
//

#include "GridSingleton_v2.h"

namespace game {

#include "GridSingleton_v2.h"

// Definição do construtor privado
    GridSingleton_v2::GridSingleton_v2(int rows, int cols) : rows(rows),
                                                             cols(cols),
                                                             terrain(rows, std::vector<char>(cols, '.')) {}

// Definição do método estático para obter a instância única
    GridSingleton_v2 &GridSingleton_v2::getInstance(int rows, int cols) {
        static GridSingleton_v2 instance(rows, cols);
        return instance;
    }



// Definição da função para definir o conteúdo de uma célula
    void GridSingleton_v2::setCell(int row, int col, char content) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            terrain[row][col] = content;
        } else {
            std::cerr << "Coordenadas inválidas." << std::endl;
        }
    }

    char GridSingleton_v2::getCell(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return terrain[row][col];
        } else {
            std::cerr << "Coordenadas inválidas." << std::endl;
            return '\0'; // Retorna um caractere nulo em caso de coordenadas inválidas
        }
    }

} // game