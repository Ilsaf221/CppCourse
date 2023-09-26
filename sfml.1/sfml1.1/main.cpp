#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({180, 480}), "title");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({160, 460});
    shape1.setPosition({10, 10});
    shape1.setFillColor(sf::Color(66, 66, 59));
    window.draw(shape1);

    sf::CircleShape shape2(70);
    shape2.setPosition({20, 20});
    shape2.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(70);
    shape3.setPosition({20, 170});
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(70);
    shape4.setPosition({20, 320});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}