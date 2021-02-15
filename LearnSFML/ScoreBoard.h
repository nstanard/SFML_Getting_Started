#pragma once
#include <SFML/Graphics.hpp>

// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Text.php
class ScoreBoard
{
public:
	ScoreBoard(float gameViewWidth, float gameViewHeight, sf::Font& font);
	~ScoreBoard();

	void Update(int playerScore);
	void Draw(sf::RenderWindow& window);

private:
	sf::Text text;
};
