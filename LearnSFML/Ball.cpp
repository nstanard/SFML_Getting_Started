#include "Ball.h"
#include <iostream>

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
	if (ball.getPosition().x >= gameViewWidth - ballSize * 2) {
		// RIGHT!
		ballAngle = 0.6;
	}
	else if (ball.getPosition().y >= gameViewHeight - ballSize * 2) {
		// BOTTOM!
		ballAngle = -.04;
	}
	else if (ball.getPosition().x <= 0 + ballSize * 2) {
		// LEFT!
	}
	else if (ball.getPosition().y <= 0 + ballSize * 2) {
		// TOP!
		ballAngle = -.04;
	}
	
	float factor = speed * deltaTime;
	float offsetX = cos(ballAngle) * factor;
	float offsetY = sin(ballAngle) * factor;
	ball.move(offsetX, offsetY);
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}
