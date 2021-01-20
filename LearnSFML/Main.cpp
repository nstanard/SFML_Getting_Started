#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;

	float displayWidth = screenWidth / 1.5;
	float displayHeight = screenHeight / 1.5;

	// | sf::Style::Fullscreen
	sf::RenderWindow window(sf::VideoMode(displayWidth, displayHeight), "LearnSFML", sf::Style::Close | sf::Style::Titlebar);

	sf::Event event;

	int accelerationV = 0;

	float paddleSpeed = 250;
	float paddleWidth = 15.0f;
	float paddleHeight = 100.0f;
	
	sf::Vector2f v2f(paddleWidth, paddleHeight);
	sf::RectangleShape rectangle(v2f);
	rectangle.setFillColor(sf::Color::White);
	
	sf::Clock clock = sf::Clock::Clock();

	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			float deltaTime = clock.restart().asSeconds();
			int positionX = rectangle.getPosition().x;
			int paddleTop = rectangle.getPosition().y; // paddle Top Y position
			int paddleBottom = rectangle.getPosition().y + paddleHeight; // paddle Bottom Y position

			if (paddleTop >= 0 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
			{
				rectangle.move(0.0f, -paddleSpeed * deltaTime); // smooth(er)
				// rectangle.move(0.0f, -0.3f); // NOT SMOOTH
			}
			if (paddleBottom <= displayHeight && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			{
				rectangle.move(0.0f, paddleSpeed * deltaTime); // smooth(er)
				// rectangle.move(0.0f, 0.3f); // NOT SMOOTH ... 
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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
