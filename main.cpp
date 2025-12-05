// g++ main.cpp -o main src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system

#include "src/Engine.h"

int main() {
    Engine engine;

    engine.run();

    return 0;
}
