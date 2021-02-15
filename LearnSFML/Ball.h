#pragma once
#include <SFML/Graphics.hpp>

// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1CircleShape.php
class Ball
{
public:
	Ball(float gameViewWidth, float gameViewHeight, float positionX, float positionY, float speed);
	~Ball();

	void Move(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::CircleShape ball;

	float speed;
	float radius;
	float ballSize;

	float gameViewWidth;
	float gameViewHeight;

	float startingX;
	float startingY;
};
