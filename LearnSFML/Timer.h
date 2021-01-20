#include <SFML/Graphics.hpp>

#pragma once
class Timer
{
public:
	Timer();
	~Timer();

	void Move(float deltaTime);
	void Draw(sf::RenderWindow window);

private:

};
