#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>

#include "game/World.h"


int main() {

    game::World world = game::World();
    world.render();



    return 0;
}
