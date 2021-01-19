#include <SFML/Graphics.hpp>
#include <iostream>

/*

Pong: https://en.wikipedia.org/wiki/Pong

Chapter 1: Paddle and ball. Objects and movement.
  - User input to move the left bar up and down, but not outsize the screen boundary.
  - Ball serves (which side should it serve to?)
  - Number of misses counted and displayed near the top middle of the screen

  Description: Right side of the screen has a solid white wall, while the left side of the screen has the single user controlled paddle.
		The ball serves randomly from the left side and bounces off the right wall as well as the top and bottom of the screen. The user has to hit the ball back to the wall, and it gets a little faster each time.
		When the user misses the ball, and it goes off the screen to the left - the number displayed near the middle top of the screen gets incremented by one.


Chapter 2: 



*/

/* 

Pong Terms
------------
 - Ball: square that bounces around
 - Paddle: the white rectangle used to hit the ball back and forth
 - Scoreboard: The numbers written to the screen to keep track of score.
*/

int main()
{
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;

	float displayWidth = screenWidth / 1.5;
	float displayHeight = screenHeight / 1.5;

	// TODO: Make screen width and screen height adjustable through UI options
	// TODO: Make fullscreen adjustable through UI options
	// | sf::Style::Fullscreen
	sf::RenderWindow window(sf::VideoMode(displayWidth, displayHeight), "LearnSFML", sf::Style::Close | sf::Style::Titlebar);

	sf::Event event;

	float paddleWidth = 15.0f;
	float paddleHeight = 100.0f;
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Vector2.php
	sf::Vector2f v2f(paddleWidth, paddleHeight);
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php
	sf::RectangleShape rectangle(v2f);
	rectangle.setFillColor(sf::Color::White);
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php
	
	/*
	float fps;
	sf::Clock clock = sf::Clock::Clock();
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;

	currentTime = clock.getElapsedTime();
	fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds()); // the asSeconds returns a float
	// std::cout << "fps =" << floor(fps) << std::endl; // flooring it will make the frame rate a rounded number
	previousTime = currentTime;
	*/

	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			int positionX = rectangle.getPosition().x;
			int paddleTop = rectangle.getPosition().y; // paddle Top Y position
			int paddleBottom = rectangle.getPosition().y + paddleHeight; // paddle Bottom Y position

			// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
			if (paddleTop >= 0 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
			{
				rectangle.move(0.0f, -0.5f);
			}
			if (paddleBottom <= displayHeight && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			{
				rectangle.move(0.0f, 0.5f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			
			sf::Text text;
			text.setString("Hello World!");
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::Red);
			text.setPosition(100.0f, 100.0f);

			std::cout << displayHeight;
			std::cout << "\n\r";
			std::cout << paddleTop;
			std::cout << "\n\r";
			std::cout << paddleBottom;
			std::cout << "\n\r";

			/* Close EVENT */
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			/* Draw Event Changes */
			window.clear();
			window.draw(text);
			window.draw(rectangle);
			window.display();
		}
	}

	return 0;
}
