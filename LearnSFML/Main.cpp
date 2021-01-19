#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "LearnSFML", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);

	sf::Event event;

	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Vector2.php
	sf::Vector2f v2f(100.0f, 100.0f);

	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php
	sf::RectangleShape rectangle(v2f);

	rectangle.setFillColor(sf::Color::White);
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php

	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php

	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				rectangle.move(-0.1f, 0.0f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				rectangle.move(0.1f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				rectangle.move(0.0f, -0.1f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				rectangle.move(0.0f, 0.1f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}

			/* Close EVENT */
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			/* Draw Event Changes */
			window.clear();
			window.draw(rectangle);
			window.display();
		}
	}

	return 0;
}
