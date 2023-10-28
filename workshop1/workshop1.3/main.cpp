#include <SFML/Graphics.hpp>
#include <cmath>

void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        defaut:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window, sf::Sprite cat)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(cat);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 1000;
    constexpr unsigned WINDOW_HEIGHT = 700;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Drawing cat", sf::Style::Default, settings);

    sf::Texture catTexture;
    sf::Sprite cat;
    catTexture.loadFromFile("D:/2ndCourse/cPlus/cppCourse/workshop1/workshop1.3/cat.png");

    cat.setTexture(catTexture);
    cat.setPosition(480, 330);

    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window, cat);
    }
}