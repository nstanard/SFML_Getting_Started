#include "Ball.h"

// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1CircleShape.php
Ball::Ball(float gameViewWidth, float gameViewHeight, float positionX, float positionY, float speed)
{
	this->gameViewWidth = gameViewWidth;
	this->gameViewHeight = gameViewHeight;

	this->speed = speed;

	radius = 10.0f;

	ball.setPosition(positionX, positionY);
	ball.setRadius(radius - 3);
	ball.setFillColor(sf::Color::White);
	ball.setOrigin(radius / 2, radius / 2);
}

Ball::~Ball()
{
}

void Ball::Move(float deltaTime)
{
	float ballVelocity = speed * deltaTime;

	if (ball.getPosition().x >= gameViewWidth - radius - 2) {

	}
	else if (ball.getPosition().x <= radius - 2) {

	}
	else if (ball.getPosition().y >= gameViewHeight - radius - 2) {

	}
	else
	{
		ball.move(ballVelocity, ballVelocity);
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}
