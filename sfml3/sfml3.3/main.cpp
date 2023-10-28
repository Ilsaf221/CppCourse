#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

void initEllipse(const sf::Vector2f &radius, sf::ConvexShape &ellipse)
{
    constexpr int pointCount = 200;
    ellipse.setPointCount(pointCount);

    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = sf::Vector2f{
            radius.x * std::sin(angle),
            radius.y * std::cos(angle)};
        ellipse.setPoint(pointNo, point);
    }
}

void initWhiteEllipse1(sf::ConvexShape &whiteEllipse)
{
    const sf::Vector2f ellipseRadius = {50.f, 90.f};
    whiteEllipse.setPosition({420, 340});
    whiteEllipse.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    initEllipse(ellipseRadius, whiteEllipse);
}

void initWhiteEllipse2(sf::ConvexShape &whiteEllipse)
{
    const sf::Vector2f ellipseRadius = {50.f, 90.f};
    whiteEllipse.setPosition({550, 340});
    whiteEllipse.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    initEllipse(ellipseRadius, whiteEllipse);
}

void initblackEllipse1(sf::ConvexShape &blackEllipse)
{
    const sf::Vector2f ellipseRadius = {12.f, 20.f};
    blackEllipse.setPosition({420, 340});
    blackEllipse.setFillColor(sf::Color(0x00, 0x00, 0x00));

    initEllipse(ellipseRadius, blackEllipse);
}

void initblackEllipse2(sf::ConvexShape &blackEllipse)
{
    const sf::Vector2f ellipseRadius = {12.f, 20.f};
    blackEllipse.setPosition({550, 340});
    blackEllipse.setFillColor(sf::Color(0x00, 0x00, 0x00));

    initEllipse(ellipseRadius, blackEllipse);
}

sf::Vector2f toEuclidean(float radius, float angle)
{
    return {
        radius * cos(angle),
        radius * sin(angle)};
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x),
                     float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        defaut:
            break;
        }
    }
}

void updateBlackEllipse(const sf::Vector2f &mousePosition, sf::ConvexShape &blackEllipse, const sf::Vector2f centerPosition)
{
    const sf::Vector2f delta = mousePosition - centerPosition;
    const float angle = atan2(delta.y, delta.x);

    const float offsetRadius = 20;
    sf::Vector2f offset;

    const float mouseDistance = sqrt(pow((mousePosition.x - centerPosition.x), 2) + pow((mousePosition.y - centerPosition.y), 2));

    if (mouseDistance <= offsetRadius)
    {
        offset = toEuclidean(mouseDistance, angle);
    }
    else
    {
        offset = toEuclidean(offsetRadius, angle);
    }

    blackEllipse.setPosition(centerPosition + offset);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &whiteEllipse1, sf::ConvexShape &whiteEllipse2, sf::ConvexShape &blackEllipse1, sf::ConvexShape &blackEllipse2)
{
    window.clear();
    window.draw(whiteEllipse1);
    window.draw(whiteEllipse2);
    window.draw(blackEllipse1);
    window.draw(blackEllipse2);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 1000;
    constexpr unsigned WINDOW_HEIGHT = 700;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Eyes2.0",
        sf::Style::Default, settings);

    sf::ConvexShape whiteEllipse1;
    sf::ConvexShape whiteEllipse2;
    sf::ConvexShape blackEllipse1;
    sf::ConvexShape blackEllipse2;
    sf::Vector2f mousePosition;

    initWhiteEllipse1(whiteEllipse1);
    initWhiteEllipse2(whiteEllipse2);
    initblackEllipse1(blackEllipse1);
    initblackEllipse2(blackEllipse2);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        updateBlackEllipse(mousePosition, blackEllipse1, whiteEllipse1.getPosition());
        updateBlackEllipse(mousePosition, blackEllipse2, whiteEllipse2.getPosition());
        redrawFrame(window, whiteEllipse1, whiteEllipse2, blackEllipse1, blackEllipse2);
    }
}
