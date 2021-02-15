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

	// Ball
	float ballSpeed = 20.0f; 
	float ballStartingX = 25;
	float ballStartingY = rand() % (int)gameViewHeight + 25;
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
			//float deltaTime = 1.0 / 60.0;
			//float deltaTime = 1.0 / 244.0;

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

/*

Notes:

 Essential Game Math: (https://www.youtube.com/watch?v=DPfxjQ6sqrc&list=RDCMUC-yuWVUplUJZvieEligKBkA&start_radio=1&t=181)
  
  - pythagorean theorem 
	- used to get distance between objects

  - vectors
	- describe a point in space and a direction
	- vectors have a length and a direction!!
	- fundamentally a vector is a right angle triangle
	- if we only care about direction, we have to convert the vector to a unit vector
	- there are 2d and 3d vectors...
	- ! sin, cos, tan, sqrt are computationally intensive, vector calculations are not though, so work in vectors when possible
	- syntax: V with arrow above, assigned to a column of params

  - vector magnitude

  - unit vectors
	- vector with a length of one

  - angles (basic trig)
	- theta - represents angle

  - S O H C A H T O A 

  - DOT PRODUCT
	- think about angles in terms of vectors

  - Linear Interpolation (LERP)
	- given two values, we can find another value in between them at any point

  - Simple Motion

  - Angles -> Trig
  - Vectors -> Geometry
  - Motion -> Kinematics
  - Matrices -> Linear Algebra
*/

/*
  Movement
	// https://en.sfml-dev.org/forums/index.php?topic=7636.0
	// https://en.sfml-dev.org/forums/index.php?topic=18953.0
	// https://gafferongames.com/post/fix_your_timestep/
*/
