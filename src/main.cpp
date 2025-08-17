#include <SFML/Graphics.hpp>

int main(){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Custom Key Lane", sf::Style::Titlebar | sf::Style::Close);

    // Load a sprite to display
    const sf::Texture texture("assets/fishe.png");
    sf::Sprite sprite(texture);
    sprite.setPosition({10.f, 50.f});
    sf::CircleShape shape(50.f);

    sf::VideoMode screenResolution = sf::VideoMode::getDesktopMode();
    auto size = window.getSize();
    window.setPosition({(int)(screenResolution.size.x - size.x) / 2, (int)(screenResolution.size.y - size.y) / 2});

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);
        window.draw(shape);

        // Update the window
        window.display();
    }

  return 0;
}
