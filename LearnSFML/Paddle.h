#include <SFML/Graphics.hpp>

#pragma once
class Paddle
{
public:
	Paddle();
	~Paddle();

	void Move(float deltaTime);
	void Draw(sf::RenderWindow window);

private:

};
