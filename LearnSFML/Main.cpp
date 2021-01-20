#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;

	float displayWidth = screenWidth / 1.5;
	float halfDisplayWidth = displayWidth / 2;
	float displayHeight = screenHeight / 1.5;
	float halfDisplayHeight = displayHeight / 2;

	// sf::Style::Fullscreen
	sf::RenderWindow window(sf::VideoMode(displayWidth, displayHeight), "LearnSFML", sf::Style::Close | sf::Style::Titlebar, settings);

	sf::Event event;

	/* TIME */
	float timer = 0;
	sf::Clock clock = sf::Clock::Clock();
	
	/* PADDLE */
	float paddleSpeed = 400.0f;
	float paddleWidth = 15.0f;
	float halfPaddleWidth = paddleWidth / 2;
	float paddleHeight = 100.0f;
	sf::Vector2f paddleVector(paddleWidth, paddleHeight);
	sf::RectangleShape paddle(paddleVector);
	paddle.setFillColor(sf::Color::White);

	/* BALL */
	const float ballSpeed = 300.0f;
	const float ballRadius = 10.0f;
	sf::CircleShape ball;
	ball.setPosition(halfDisplayWidth, halfDisplayHeight);
	ball.setRadius(ballRadius - 3);
	ball.setFillColor(sf::Color::White);
	ball.setOrigin(ballRadius / 2, ballRadius / 2);

	/* SCORE */
	sf::Font font;
	if (!font.loadFromFile("consola.ttf"))
		return EXIT_FAILURE;

	sf::Text text;
	text.setFont(font);
	text.setString("0");
	text.setPosition(halfDisplayWidth, 0);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);

	/* TIMER */
	sf::Text timerOutput;
	timerOutput.setFont(font);
	timerOutput.setPosition(displayWidth - 100, displayHeight - 25);
	timerOutput.setCharacterSize(25);
	timerOutput.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			float deltaTime = clock.restart().asSeconds();
			timer += deltaTime;
			timerOutput.setString(std::to_string(timer));

			// TODO: Make paddle it's own class with move/draw methods
			/* PADDLE CONTROL */
			int paddleTop = paddle.getPosition().y; // paddle Top Y position
			int paddleBottom = paddle.getPosition().y + paddleHeight; // paddle Bottom Y position
			float paddleVelocity = ballSpeed * deltaTime;

			if (paddleTop >= 0 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
			{
				paddle.move(0.0f, -paddleVelocity);
			}

			if (paddleBottom <= displayHeight && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			{
				paddle.move(0.0f, paddleVelocity);
			}
			/* END PADDLE CONTROL */

			// TODO: Make ball it's own class with move/draw methods
			/* BALL CONTROL */
			int ballX = ball.getPosition().x; // paddle Top X position
			int ballY = ball.getPosition().y; // paddle Top Y position
			float ballVelocity = ballSpeed * deltaTime;

			if (ballX >= displayWidth) {
				
			}
			else if (ballX <= 0) {
				
			}
			else if (ballY >= displayHeight) {
				
			}
			else
			{
				ball.move(ballVelocity, ballVelocity);
			}
			/* END BALL CONTROL */

			/* CLOSE */
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
				window.close();

			/* CLEAR */
			window.clear(sf::Color(50, 200, 50));

			/* DRAW */
			window.draw(paddle);
			window.draw(ball);
			window.draw(text);
			window.draw(timerOutput);

			/* DISPLAY */
			window.display();
		}
	}

	return EXIT_SUCCESS;
}
