#include <iostream>
#include "Paddle.h"

Paddle::Paddle(float gameViewWidth, float gameViewHeight, float speed)
{
	this->gameViewWidth = gameViewWidth;
	this->gameViewHeight = gameViewHeight;

	this->height = 100.0f;
	this->width = 15.0f;
	this->speed = 400.0f;

	paddle.setSize(sf::Vector2f(width, height));
	paddle.setFillColor(sf::Color::White);
}

Paddle::~Paddle()
{
}

void Paddle::Move(float deltaTime)
{
	float velocity = speed * deltaTime;

	if (paddle.getPosition().y >= 0 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
	{
		paddle.move(0.0f, -velocity);
	}

	if ((paddle.getPosition().y + height) <= gameViewHeight && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{
		paddle.move(0.0f, velocity);
	}
}

void Paddle::Draw(sf::RenderWindow& window)
{
	window.draw(paddle);
}
