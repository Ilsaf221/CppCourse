#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RectangleShape s1;
    s1.setSize({160, 20});
    s1.setPosition({50, 50});
    s1.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape s2;
    s2.setSize({20, 160});
    s2.setPosition({50, 50});
    s2.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape s3;
    s3.setSize({160, 20});
    s3.setPosition({50, 190});
    s3.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape s4;
    s4.setSize({20, 160});
    s4.setPosition({190, 190});
    s4.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape s5;
    s5.setSize({160, 20});
    s5.setPosition({50, 330});
    s5.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape i11;
    i11.setSize({150, 20});
    i11.setPosition({290, 50});
    i11.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape i12;
    i12.setSize({20, 280});
    i12.setPosition({355, 50});
    i12.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape i13;
    i13.setSize({150, 20});
    i13.setPosition({290, 330});
    i13.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape i21;
    i21.setSize({150, 20});
    i21.setPosition({520, 50});
    i21.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape i22;
    i22.setSize({20, 280});
    i22.setPosition({585, 50});
    i22.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RectangleShape i23;
    i23.setSize({150, 20});
    i23.setPosition({520, 330});
    i23.setFillColor(sf::Color(0xFF, 0x0, 0x0));

    sf::RenderWindow window(sf::VideoMode({720, 400}), "Convex Shapes");
    window.clear();
    window.draw(s1);
    window.draw(s2);
    window.draw(s3);
    window.draw(s4);
    window.draw(s5);
    window.draw(i11);
    window.draw(i12);
    window.draw(i13);
    window.draw(i21);
    window.draw(i22);
    window.draw(i23);

    window.display();

    sf::sleep(sf::seconds(5));
}