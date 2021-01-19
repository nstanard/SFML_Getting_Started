#include <SFML/Graphics.hpp>
#include <iostream>
#include "Main.h"

int main()
{
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "LearnSFML", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	return 0;
}
