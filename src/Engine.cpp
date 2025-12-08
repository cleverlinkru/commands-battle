#include "Engine.h"

Engine::Engine()
{
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window = new sf::RenderWindow(
        sf::VideoMode(resolution.x, resolution.y),
        "Command battle",
        sf::Style::Resize + sf::Style::Close
    );

    window->setMouseCursorVisible(false);

    panel = new Panel(window);

    cursor = new Cursor(window);

    Camera* camera = new Camera(0, 0, resolution.x, resolution.y, window);

    WorldGenerator* wg = new WorldGenerator();
    world = wg->create(camera);

    visibleMaskCreator = new VisibleMaskCreator(world);
}

void Engine::run()
{
    while (window->isOpen())
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
