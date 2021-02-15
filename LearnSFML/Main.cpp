#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h";
#include "Paddle.h";
#include "ScoreBoard.h";

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
	
	// Ball
	float ballSpeed = 200.0f; 
	float ballStartingX = 25;
	float ballStartingY = 25;
	Ball ball(gameViewWidth, gameViewHeight, ballStartingX, ballStartingY, ballSpeed);

	// Paddle
	float paddleSpeed = 100.0f;
	Paddle paddle(gameViewWidth, gameViewHeight, paddleSpeed);

	// Score
	sf::Font font;
	if (!font.loadFromFile("consola.ttf"))
		return EXIT_FAILURE;

	int playerScore = 0;
	ScoreBoard scoreBoard(gameViewWidth, gameViewHeight, font, playerScore);


	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			float deltaTime = clock.restart().asSeconds();

			/* MOVE & UPDATE */
			ball.Move(deltaTime);
			paddle.Move(deltaTime);
			scoreBoard.Update(playerScore);

			/* CLOSE */
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
				window.close();

			/* CLEAR */
			window.clear();

			/* DRAW */
			ball.Draw(window);
			paddle.Draw(window);
			scoreBoard.Draw(window);

			/* DISPLAY */
			window.display();
		}
	}

	return EXIT_SUCCESS;
}
