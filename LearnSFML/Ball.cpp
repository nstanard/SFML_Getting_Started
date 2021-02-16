#include "Ball.h"
#include <string>

// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1CircleShape.php
Ball::Ball(float gameViewWidth, float gameViewHeight, float positionX, float positionY, float speed, float ballAngle)
{
	this->gameViewWidth = gameViewWidth;
	this->gameViewHeight = gameViewHeight;
	this->speed = speed;
	this->ballAngle = ballAngle;

	this->startingX = positionX;
	this->startingY = positionY;

	radius = 10.0f;
	ballSize = radius - 3;

	ball.setPosition(startingX, startingY);
	ball.setRadius(radius - 3);
	ball.setFillColor(sf::Color::White);
	//ball.setOrigin(radius / 2, radius / 2);

	font.loadFromFile("consola.ttf");
}

Ball::~Ball()
{
}

void Ball::Move(float deltaTime)
{
	// detect wall collisions
	bool rightWallHit = ball.getPosition().x >= gameViewWidth - radius;
	bool leftWallHit = ball.getPosition().x <= 0;
	bool bottomWallHit = ball.getPosition().y >= gameViewHeight - radius;
	bool topWallHit = ball.getPosition().y <= 0;

	if (rightWallHit) {
		//speed += 50;
		ballAngle = pi - ballAngle;
		ball.setPosition(ball.getPosition().x - radius, ball.getPosition().y);
	}
	else if (bottomWallHit) {
		//speed += 50;
		ballAngle *= -1;
		ball.setPosition(ball.getPosition().x, gameViewHeight - radius);
	}
	else if (leftWallHit) {
		//speed += 50;
		ballAngle = pi - ballAngle;
		ball.setPosition(ball.getPosition().x + radius, ball.getPosition().y);
	}
	else if (topWallHit) {
		//speed += 50;
		ballAngle *= -1;
		ball.setPosition(ball.getPosition().x, 0 + radius);
	}
	//else {
	float factor = speed * deltaTime;
	float offsetX = cos(ballAngle) * factor;
	float offsetY = sin(ballAngle) * factor;
	ball.move(offsetX, offsetY);
	//}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(15);
	//text.setString("Angle: " + std::to_string(ballAngle));
	//text.setString("Origin: " + std::to_string(ball.getOrigin().x) + " " + std::to_string(ball.getOrigin().y));
	text.setPosition(10, gameViewHeight - 20);
	window.draw(text);
}
