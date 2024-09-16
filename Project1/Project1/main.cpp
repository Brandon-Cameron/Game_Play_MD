#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Match 3");

	std::srand(std::time(nullptr));

	sf::RectangleShape player[81];


	int gridData[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	for (int i = 0; i < 64; i++)
	{
		gridData[i] = (std::rand() % 5) + 1;
	};

	int xOffset = 100;
	int yOffset = 100;
	int tileNo = 0;


	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Clock clockForFrameRate;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		timeSinceLastUpdate += clockForFrameRate.restart();

		if (timeSinceLastUpdate > timePerFrame)
		{

			for (int i = 0; i < 8; i++)
			{
				xOffset = 100;
				for (int i = 0; i < 8; i++)
				{
					if (gridData[tileNo] == 1)
					{
						player[tileNo].setSize(sf::Vector2f(100, 100));
						player[tileNo].setFillColor(sf::Color::Magenta);
						player[tileNo].setPosition(xOffset, yOffset);
					}
					if (gridData[tileNo] == 2)
					{
						player[tileNo].setSize(sf::Vector2f(100, 100));
						player[tileNo].setFillColor(sf::Color::Cyan);
						player[tileNo].setPosition(xOffset, yOffset);
					}
					if (gridData[tileNo] == 3)
					{
						player[tileNo].setSize(sf::Vector2f(100, 100));
						player[tileNo].setFillColor(sf::Color::Red);
						player[tileNo].setPosition(xOffset, yOffset);
					}
					if (gridData[tileNo] == 4)
					{
						player[tileNo].setSize(sf::Vector2f(100, 100));
						player[tileNo].setFillColor(sf::Color::Green);
						player[tileNo].setPosition(xOffset, yOffset);
					}
					if (gridData[tileNo] == 5)
					{
						player[tileNo].setSize(sf::Vector2f(100, 100));
						player[tileNo].setFillColor(sf::Color::Yellow);
						player[tileNo].setPosition(xOffset, yOffset);
					}
					tileNo++;
					xOffset += 100;
				}
				yOffset += 100;
			}

			tileNo = 0;
			xOffset = 100;
			yOffset = 100;



			window.clear();

			for (int i = 0; i < 64; i++)
			{
				//player[i].setPosition(player[i].getPosition().x + 1, player[i].getPosition().y);
				window.draw(player[i]);
			};

			window.display();
			timeSinceLastUpdate = sf::Time::Zero;
		}

	}

	return 1;	
}