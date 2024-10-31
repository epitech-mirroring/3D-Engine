/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "engine3D/Engine3D.hpp"
#include "common/factories/ComponentFactory.hpp"
#include "graphics3D/components/Cube.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    try {
        Engine3D const engine([]() {
            REGISTER_COMPONENT(Cube);
        }, "Demo");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
