#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;

	float displayWidth = screenWidth / 1.5;
	float halfDisplayWidth = displayWidth / 2;
	float displayHeight = screenHeight / 1.5;
	float halfDisplayHeight = displayHeight / 2;

	// | sf::Style::Fullscreen
	sf::RenderWindow window(sf::VideoMode(displayWidth, displayHeight), "LearnSFML", sf::Style::Close | sf::Style::Titlebar);

	sf::Event event;

	sf::Clock clock = sf::Clock::Clock();

	// TODO: Implement acceleration?
	int accelerationV = 0;

	float paddleSpeed = 200; // 200 - 250 seems to be the max speed we should set... higher and it "lags"
	float paddleWidth = 15.0f;
	float halfPaddleWidth = paddleWidth / 2;
	float paddleHeight = 100.0f;
	
	/* PADDLE */
	sf::Vector2f paddleVector(paddleWidth, paddleHeight);
	sf::RectangleShape paddle(paddleVector);
	paddle.setFillColor(sf::Color::White);

	/* BALL */
	sf::CircleShape ball(10.f);
	ball.setPosition(halfDisplayWidth, halfDisplayHeight);

	/* WALL */
	sf::Vector2f rightWallVector(halfPaddleWidth, displayHeight);
	sf::RectangleShape rightWall(rightWallVector);
	rightWall.setFillColor(sf::Color::White);
	rightWall.setPosition(displayWidth - halfPaddleWidth, 0);

	/* SCORE / TEXT */
	sf::Font font;
	font.loadFromFile("consola.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("0");
	text.setPosition(halfDisplayWidth, 0);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			float deltaTime = clock.restart().asSeconds();
			int positionX = paddle.getPosition().x;
			int paddleTop = paddle.getPosition().y; // paddle Top Y position
			int paddleBottom = paddle.getPosition().y + paddleHeight; // paddle Bottom Y position

			if (paddleTop >= 0 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
			{
				paddle.move(0.0f, -paddleSpeed * deltaTime); // smooth(er), but not as good as we want
			}
			if (paddleBottom <= displayHeight && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			{
				paddle.move(0.0f, paddleSpeed * deltaTime); // smooth(er), but not as good as we want
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			
			/* CLOSE */
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			/* CLEAR */
			window.clear();

			/* DRAW */
			window.draw(paddle);
			window.draw(ball);
			window.draw(rightWall);
			window.draw(text);

			/* DISPLAY */
			window.display();
		}
	}

	return 0;
}
