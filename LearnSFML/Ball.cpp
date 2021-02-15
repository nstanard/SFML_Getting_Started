#include "Ball.h"
#include <iostream>

// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1CircleShape.php
Ball::Ball(float gameViewWidth, float gameViewHeight, float positionX, float positionY, float speed)
{
	this->gameViewWidth = gameViewWidth;
	this->gameViewHeight = gameViewHeight;
	this->speed = speed;

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
	// Velocity = Speed in a given direction
	float ballVelocity = speed * deltaTime;
	float velocityX = ballVelocity;
	float velocityY = ballVelocity;

	if (ball.getPosition().x >= gameViewWidth - ballSize * 2) {
		// RIGHT!
		//ball.setPosition(startingX, startingY);
	}
	else if (ball.getPosition().y >= gameViewHeight - ballSize * 2) {
		// BOTTOM!
		//ball.setPosition(startingX, startingY);
	}
	else if (ball.getPosition().x <= 0 + ballSize * 2) {
		// LEFT!
		//ball.setPosition(startingX, startingY);
	}
	else if (ball.getPosition().y <= 0 + ballSize * 2) {
		// TOP!
		//ball.setPosition(startingX, startingY);
	}
	else
	{
		//ball.move(-.05, .05); // left, down
		//ball.move(-.05, -.05); // left, up
		//ball.move(.05, -.05); // right, up
		//ball.move(.05, .05); // right, down
		
		ball.move(velocityX, velocityY);
	}

}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}
