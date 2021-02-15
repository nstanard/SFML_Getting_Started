#include "ScoreBoard.h"
#include <iostream>

ScoreBoard::ScoreBoard(float gameViewWidth, float gameViewHeight, sf::Font& font)
{
	float halfGameViewWidth = gameViewWidth / 2;

	text.setString("0");
	text.setCharacterSize(50);
	text.setFont(font);
	text.setPosition(10, 10);
}

ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::Update(int playerScore)
{
	std::string score = std::to_string(playerScore);
	text.setString(score);
}

void ScoreBoard::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}
