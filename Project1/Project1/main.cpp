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
#include <vector>

class Tile
{
public:

	void create(int t_type, int t_x, int t_y)
	{
		m_type = t_type;

		m_shape.setSize(sf::Vector2f(100, 100));
		if (t_type == 0)
		{
			m_shape.setFillColor(sf::Color::Transparent);
		}
		if (t_type == 1)
		{
			m_shape.setFillColor(sf::Color::Magenta);
		}
		if (t_type == 2)
		{
			m_shape.setFillColor(sf::Color::Cyan);
		}
		if (t_type == 3)
		{
			m_shape.setFillColor(sf::Color::Red);
		}
		if (t_type == 4)
		{
			m_shape.setFillColor(sf::Color::Green);
		}
		if (t_type == 5)
		{
			m_shape.setFillColor(sf::Color::Yellow);
		}
		m_shape.setPosition(t_x, t_y);
	}

	int getType()
	{
		return m_type;
	}

	int m_type;
	sf::RectangleShape m_shape;

};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Match 3");

	std::srand(std::time(nullptr));

	Tile tiles[81];


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

	/*for (int i = 0; i < 64; i++)
	{
		gridData[i] = (std::rand() % 5) + 1;
	};*/

	int xOffset = 100;
	int yOffset = 100;
	int tileNo = 0;
	int dropCount = 0;


	sf::Time timePerFrame = sf::seconds(1.0f / 5.0f);
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
		{	// CODE FOR UPDATE THE BOARD, CREATING AND DROPPING TILES
			if (dropCount == 10)
			{
				for (int i = 0; i < 8; i++)
				{
					if (gridData[i] == 0)
					{
						tiles[i].create((std::rand() % 5) + 1, xOffset, yOffset);
						gridData[i] = tiles[i].m_type;

						xOffset += 100;

					}
				}
				for (int row = 0; row < 7; row++)
				{
					xOffset = 100;
					for (int col = 0; col < 8; col++)
					{
						if (gridData[(col + 8 * row) + 8] == 0)
						{
							//tiles[i + 8].create(tiles[i].m_type, xOffset, yOffset);
							gridData[(col + 8 * row) + 8] = gridData[(col + 8 * row)];
							gridData[col + 8 * row] = 0;

							//tiles[i].m_type = 0;

							xOffset += 100;
						}
					}
					yOffset += 100;
				}
				dropCount = 0;


				yOffset = 100;
				std::cout << "********************" << "\n";
				for (int row = 0; row < 8; row++)
				{
					for (int col = 0; col < 8; col++)
					{
						std::cout << gridData[col + (row * 8)];
					}
					std::cout << "\n";

				}
				std::cout << "********************" << "\n";


				for (int i = 0; i < 8; i++)
				{
					xOffset = 100;
					for (int i = 0; i < 8; i++)
					{
						tiles[tileNo].create(gridData[tileNo], xOffset, yOffset);

						tileNo++;
						xOffset += 100;
					}
					yOffset += 100;
				}


				tileNo = 0;
				std::cout << tiles[30].m_type << "\n";

				// CHECK AND REMOVE MATCHED TILES

				for (int row = 0; row < 8; row++)
				{
					for (int col = 0; col < 8; col++)
					{
						int index = col + 8 * row;

						if(gridData[index] == gridData[index + 8] && gridData[index] == gridData[index - 8])
						{
							gridData[col + 8 * row] = 0;
							gridData[(col + 8 * row) + 8] = 0;
							gridData[(col + 8 * row) - 8] = 0;
							//std::cout << "Vertical Clear: " << tiles[tileNo - 8].m_type << tiles[tileNo].m_type << tiles[tileNo + 8].m_type << "\n";
							
						}

						tileNo++;
					}
				}
			}

			tileNo = 0;
			xOffset = 100;
			yOffset = 100;
			dropCount++;



			window.clear();

			for (int i = 0; i < 64; i++)
			{
				//player[i].setPosition(player[i].getPosition().x + 1, player[i].getPosition().y);
				window.draw(tiles[i].m_shape);
			};

			window.display();
			timeSinceLastUpdate = sf::Time::Zero;
		}

	}

	return 1;	
}