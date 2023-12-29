//
// Created by certi on 12/29/23.
//

#ifndef CMAKESFMLPROJECT_GRIDSINGLETON_V2_H
#define CMAKESFMLPROJECT_GRIDSINGLETON_V2_H

#include <iostream>
#include <vector>

namespace game {

    class GridSingleton_v2 {
    private:
        int rows;
        int cols;
        std::vector<std::vector<char>> terrain;

        // Construtor privado para evitar instâncias diretas
        GridSingleton_v2(int rows, int cols);

    public:
        // Método estático para obter a instância única
        static GridSingleton_v2& getInstance(int rows, int cols);

        // Função para definir o conteúdo de uma célula
        void setCell(int row, int col, char content);

        // Função para obter o conteúdo de uma célula
        [[nodiscard]] char getCell(int row, int col) const;


    };


} // game

#endif //CMAKESFMLPROJECT_GRIDSINGLETON_V2_H
