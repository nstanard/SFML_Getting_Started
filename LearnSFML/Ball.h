#pragma once
#include <SFML/Graphics.hpp>

// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1CircleShape.php
class Ball
{
public:
	Ball(float gameViewWidth, float gameViewHeight, float positionX, float positionY, float speed, float ballAngle);
	~Ball();

	void Move(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::CircleShape ball;

	const double pi = 3.14159265358979323846;
	float speed;
	float radius;
	float ballSize;
	float ballAngle;

	float gameViewWidth;
	float gameViewHeight;

	float startingX;
	float startingY;

	sf::Font font;
};
