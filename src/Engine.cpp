#include "Engine.h"

Engine::Engine()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    window.create(
        VideoMode(resolution.x, resolution.y),
        "Command battle",
        sf::Style::Resize + sf::Style::Close
    );
}

void Engine::run()
{
    while (window.isOpen())
    {
        input();
        update();
        draw();
    }
}
