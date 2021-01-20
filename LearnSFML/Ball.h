#pragma once
#include <SFML/Graphics.hpp>

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

	float gameViewWidth;
	float gameViewHeight;
};
