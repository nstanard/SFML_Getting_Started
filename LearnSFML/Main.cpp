#include <SFML/Graphics.hpp>
#include <iostream>

#include <stdlib.h>
#include <time.h>

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
	window.setVerticalSyncEnabled(true); // https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Window.php#a59041c4556e0351048f8aff366034f61

	sf::Event event;

	sf::Clock clock = sf::Clock::Clock();
	
	/* initialize random seed */
	srand(time(NULL));

	const float pi = 3.14159f;

	// Ball
	int angleSeed = rand() % 60 + 1;
	int upOrDown = angleSeed % 2;
	float scaledAngle = angleSeed * .01;
	if (upOrDown == 0) {
		scaledAngle = -scaledAngle;
	}
	float ballAngle = scaledAngle;

	float ballStartingX = gameViewWidth / 2;
	float ballStartingY = gameViewHeight / 2;

	float ballSpeed = 200.0f;

	Ball ball(gameViewWidth, gameViewHeight, ballStartingX, ballStartingY, ballSpeed, ballAngle);

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
