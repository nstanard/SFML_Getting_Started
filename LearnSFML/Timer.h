#pragma once
#include <SFML/Graphics.hpp>

class Timer
{
public:
	Timer();
	~Timer();

	void Move(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:

};
