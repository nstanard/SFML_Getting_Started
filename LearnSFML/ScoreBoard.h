#include <SFML/Graphics.hpp>

#pragma once
class ScoreBoard
{
public:
	ScoreBoard();
	~ScoreBoard();

	void Move(float deltaTime);
	void Draw(sf::RenderWindow window);

private:

};
