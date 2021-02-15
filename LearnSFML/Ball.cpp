#include "Ball.h"
#include <iostream>

// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1CircleShape.php
Ball::Ball(float gameViewWidth, float gameViewHeight, float positionX, float positionY, float speed)
{
	this->gameViewWidth = gameViewWidth;
	this->gameViewHeight = gameViewHeight;
	this->speed = speed;

	radius = 10.0f;

	//std::cout << gameViewHeight;
	// https://www.cplusplus.com/reference/cstdlib/rand/
	// 0 -> gameViewHeight
	//startingY = rand() % gameViewHeight;

	ball.setPosition(positionX, positionY);
	ball.setRadius(radius - 3);
	ball.setFillColor(sf::Color::White);
	ball.setOrigin(radius / 2, radius / 2);
}

Ball::~Ball()
{
}

/*
	Direction Vectors & Dot Products
	 - relationship between unit vectors represented as a scaler value, the dot product
*/
void Ball::Move(float deltaTime)
{
	// Velocity = Speed in a given direction
	float ballVelocity = speed * deltaTime;
	float velocityX = ballVelocity;
	float velocityY = ballVelocity;

	if (ball.getPosition().x >= gameViewWidth - radius - 2) {

	}
	else if (ball.getPosition().x <= radius - 2) {

	}
	else if (ball.getPosition().y >= gameViewHeight - radius - 2) {

	}
	else
	{
		//ball.move(-.05, .05); // left, down
		//ball.move(-.05, -.05); // left, up
		//ball.move(.05, -.05); // right, up
		//ball.move(.05, .05); // right, up

		ball.move(velocityX, velocityY);
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}
