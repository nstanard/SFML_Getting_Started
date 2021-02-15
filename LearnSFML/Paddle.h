#pragma once
#include <SFML/Graphics.hpp>

// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php
class Paddle
{
public:
	Paddle(float gameViewWidth, float gameViewHeight, float speed);
	~Paddle();

	void Move(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape paddle;

	float speed;
	float width;
	float height;

	float gameViewWidth;
	float gameViewHeight;
};
