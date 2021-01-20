#include <SFML/Graphics.hpp>

#pragma once
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
