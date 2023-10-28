#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>

void init(sf::ConvexShape &arrow)
{
    const sf::Vector2f position = {500, 350};
    arrow.setPointCount(7);
    arrow.setPoint(0, {90, 0});
    arrow.setPoint(1, {30, 60});
    arrow.setPoint(2, {30, 30});
    arrow.setPoint(3, {-30, 30});
    arrow.setPoint(4, {-30, -30});
    arrow.setPoint(5, {30, -30});
    arrow.setPoint(6, {30, -60});
    arrow.setFillColor(sf::Color(0xFF, 0xFF, 0));
    arrow.setPosition(position);
    arrow.setOutlineColor(sf::Color(0x00, 0x00, 0x00));
    arrow.setOutlineThickness(3);
    arrow.setOrigin({90, 0});
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

void updateRotation(sf::ConvexShape &arrow, const float angle, const float dt)
{
    const float rotationSpeed = 90;
    const float maxRotation = rotationSpeed * dt;

    const float arrowRotation = arrow.getRotation();
    float deltaAngle = toDegrees(angle) - arrowRotation;

    if (deltaAngle > 180)
    {
        deltaAngle -= 360;
    }
    else if (deltaAngle < -180)
    {
        deltaAngle += 360;
    }

    deltaAngle = std::max(-maxRotation, std::min(deltaAngle, maxRotation));
    arrow.setRotation(arrowRotation + deltaAngle);
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &arrow, sf::Clock &clock)
{
    const float dt = clock.restart().asSeconds();

    sf::Vector2f arrowPosition = arrow.getPosition();
    const sf::Vector2f delta = mousePosition - arrowPosition;
    const float angle = atan2(delta.y, delta.x);

    updateRotation(arrow, angle, dt);

    const float speed = 20;
    const float oneFrameWay = speed * dt;

    const sf::Vector2f motion = mousePosition - arrowPosition;
    sf::Vector2f direction;

    if (((motion.x <= 0.5) && (motion.x >= -0.5)) || ((motion.y <= 0.5) && (motion.y >= -0.5)))
    {
        direction = {0, 0};
    }
    else
    {
        direction = {motion.x / sqrt(pow(motion.x, 2) + pow(motion.y, 2)),
                     motion.y / sqrt(pow(motion.x, 2) + pow(motion.y, 2))};
    }
    arrowPosition = arrowPosition + direction * oneFrameWay;
    arrow.setPosition(arrowPosition);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &arrow)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(arrow);
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
        "Yellow arrow", sf::Style::Default, settings);

    sf::ConvexShape arrow;
    sf::Vector2f mousePosition;
    sf::Clock clock;

    init(arrow);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, arrow, clock);
        redrawFrame(window, arrow);
    }
}