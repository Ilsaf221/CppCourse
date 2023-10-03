#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr int pointCount = 200;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({1600, 1200}), "Polar Rose",
        sf::Style::Default, settings);

    sf::ConvexShape shape;
    const sf::Vector2f centerPosition = {800.f, 560.f};
    shape.setFillColor(sf::Color(0xFF, 0x09, 0x80));

    shape.setPointCount(pointCount);

    while (window.isOpen())
    {
        for (float i = 1; i <= 360; i = i + 0.2)
        {

            for (int pointNo = 0; pointNo < pointCount; ++pointNo)
            {
                float angle = float(2 * M_PI * pointNo) / float(pointCount);
                const float ellipseRadius = 200 * std::sin(6 * angle);
                sf::Vector2f point = sf::Vector2f{
                    ellipseRadius * std::sin(angle),
                    ellipseRadius * std::cos(angle)};
                shape.setPoint(pointNo, point);
            }
            sf::Vector2f position = sf::Vector2f{
                300 * std::sin(float(i * 2 * M_PI / 180)),
                300 * std::cos(float(i * 2 * M_PI / 180))};

            shape.setPosition(centerPosition + position);
            shape.setRotation(3 * i);
            window.clear();
            window.draw(shape);
            window.display();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }
}
