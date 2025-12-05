#include "Engine.h"

Engine::Engine()
{
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window.create(
        sf::VideoMode(resolution.x, resolution.y),
        "Command battle",
        sf::Style::Resize + sf::Style::Close
    );

    WorldGenerator* wg = new WorldGenerator();
    World* world = wg->create();

    camera = new Camera(0, 0, resolution.x, resolution.y, world, &window);

    control = new Control(camera);
}

void Engine::run()
{
    while (window.isOpen())
    {
        delay();
        input();
        update();
        draw();
    }
}

void Engine::delay()
{
        auto start = std::chrono::high_resolution_clock::now();
        long elapsed;
        do {
            auto now = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(now - start);
            elapsed = duration.count();
        } while (elapsed >= 16666);
        start += std::chrono::microseconds(16666);
}
