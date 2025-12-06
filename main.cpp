// g++ main.cpp -o main src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system

// mkdir Build
// cd Build
// cmake ..
// cmake --build .
// ./CommandBattle

#include "src/Engine.h"

int main() {
    Engine engine;

    engine.run();

    return 0;
}
