#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(93, 31, 22));
    roof.setPosition({500, 350});
    roof.setPointCount(4);
    roof.setPoint(0, {-100, 0});
    roof.setPoint(1, {+100, 0});
    roof.setPoint(2, {+260, 110});
    roof.setPoint(3, {-260, 110});

    sf::RectangleShape wall;
    wall.setSize({410, 210});
    wall.setPosition({290, 460});
    wall.setFillColor(sf::Color(77, 47, 11));

    sf::RectangleShape door;
    door.setSize({70, 150});
    door.setPosition({340, 520});
    door.setFillColor(sf::Color(25, 23, 22));

    sf::RectangleShape pipe;
    pipe.setSize({35, 64});
    pipe.setPosition({554, 344});
    pipe.setFillColor(sf::Color(60, 57, 55));

    sf::RectangleShape upperPipe;
    upperPipe.setSize({59, 39});
    upperPipe.setPosition({542, 305});
    upperPipe.setFillColor(sf::Color(60, 57, 55));

    sf::CircleShape smoke1(16);
    smoke1.setPosition({568, 275});
    smoke1.setFillColor(sf::Color(192, 192, 192));

    sf::CircleShape smoke2(18);
    smoke2.setPosition({577, 249});
    smoke2.setFillColor(sf::Color(192, 192, 192));

    sf::CircleShape smoke3(22);
    smoke3.setPosition({591, 220});
    smoke3.setFillColor(sf::Color(192, 192, 192));

    sf::CircleShape smoke4(23);
    smoke4.setPosition({600, 197});
    smoke4.setFillColor(sf::Color(192, 192, 192));

    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Convex Shapes");
    window.clear();
    window.draw(roof);
    window.draw(wall);
    window.draw(door);
    window.draw(pipe);
    window.draw(smoke1);
    window.draw(upperPipe);
    window.draw(smoke2);
    window.draw(smoke3);
    window.draw(smoke4);
    window.display();

    sf::sleep(sf::seconds(5));
}