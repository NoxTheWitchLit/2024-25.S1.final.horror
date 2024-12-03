#include <SFML/Graphics.hpp>
#include <iostream>
//future libraries:
//https://github.com/MiguelMJ/Candle
using namespace std;
int main()
{

    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

    //Game Loop

    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    player.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {

        //create an event
        sf::Event evnt;
        //create a rectangle shape called player
        
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                cout << "New window width: " << evnt.size.width << " New window height: " << evnt.size.height << endl;
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128) {
                    printf("%c", evnt.text.unicode);
                }
            }

        } //window event

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            player.move(-0.1f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            player.move(0.1f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            player.move(0.0f, -0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            player.move(0.0f, 0.1f);
        }


        //display player

        window.clear();
        window.draw(player);
        window.display();
    }
    return 0;

}
