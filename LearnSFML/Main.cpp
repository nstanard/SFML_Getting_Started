#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h";

int main()
{
	// GAME SETTINGS
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// MONITOR SIZE
	int displayWidth = sf::VideoMode::getDesktopMode().width;
	int displayHeight = sf::VideoMode::getDesktopMode().height;

	// GAME VIEW
	float viewScale = 2;
	float gameViewWidth = displayWidth / viewScale;
	float gameViewHeight = displayHeight / viewScale;
	sf::RenderWindow window(sf::VideoMode(gameViewWidth, gameViewHeight), "Pong", sf::Style::Close | sf::Style::Titlebar, settings);

	sf::Event event;

	sf::Clock clock = sf::Clock::Clock();
	
	// GAME VISUALS
	float ballSpeed = 100.0f;
	float ballStartingX = 25; // gameViewWidth / 2
	float ballStartingY = 25; // gameViewHeight / 2
	Ball ball(gameViewWidth, gameViewHeight, ballStartingX, ballStartingY, ballSpeed);

	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			float deltaTime = clock.restart().asSeconds();

			ball.Move(deltaTime);

			/* CLOSE */
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
				window.close();

			/* CLEAR */
			window.clear();

			/* DRAW */
			ball.Draw(window);

			/* DISPLAY */
			window.display();
		}
	}

	return EXIT_SUCCESS;
}
