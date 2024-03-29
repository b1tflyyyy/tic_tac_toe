#include <iostream>
#include <thread>

#include "../tic_tac_toe.BL/Model/Map/Map.h"
#include "../tic_tac_toe.BL/Controller/MapController/MapController.h"

#include "../tic_tac_toe.BL/Model/Player/Player.h"
#include "../tic_tac_toe.BL/Controller/PlayerController/PlayerController.h"


void Print(model::map::Map& map);

int main()
{
	std::cout << "Hello, dear user!\n";
	std::cout << "Tic Tac Toe Game\n";

	std::this_thread::sleep_for(std::chrono::milliseconds(1500));

	model::map::Map map;
	model::player::Player player;

	controller::map::MapController mapController;
	controller::player::PlayerController playerController;

	std::uint16_t x = 0;
	std::uint16_t y = 0;


	std::uint16_t counter = 0;

	while (true)
	{
		++counter;

		Print(map);

		std::cout << "Current player: " << player.GetPlayer() << '\n';

		std::cout << "Enter x position: ";
		std::cin >> x;

		std::cout << "Enter y position: ";
		std::cin >> y;

		if (!mapController.SetPlayerOnMap(map, x, y, player))
		{
			std::cout << "Error x and y position\n";
			std::cout << "Try again!\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			continue;
		}
		if (counter >= 5)
		{
			if (mapController.IsWinCombination(map, player))
			{
				Print(map);

				std::cout << "Player " << player.GetPlayer() << " win!!!!\n";

				// clear the data
				counter = 0;
				mapController.ClearMap(map);

				std::cout << "If you want to continue the game, write 0, otherwise 1.\n";
				
				std::uint16_t input = 0;
				std::cin >> input;

				if (input)
				{
					return 0;
				}
			}
			else if (mapController.IsDraw(map))
			{
				Print(map);

				std::cout << "Draws.\n";

				// clear the data
				counter = 0;
				mapController.ClearMap(map);

				std::cout << "If you want to continue the game, write 0, otherwise 1.\n";

				std::uint16_t input = 0;
				std::cin >> input;

				if (input)
				{
					return 0;
				}
			}
		}

		playerController.ChangePlayer(player);
	}

	return 0;
}


void Print(model::map::Map& map)
{
	system("cls");

	for (std::uint16_t i = 0; i < map.GetAmountRow(); ++i)
	{
		for (std::uint16_t j = 0; j < map.GetAmountColumn(); ++j)
		{
			std::cout << map.GetElement(i, j);

			// if this is not the last column, then we draw '|'
			if (!(j == map.GetAmountColumn() - 1))
			{
				std::cout << '|';
			}	
		}
	
		std::cout << '\n';

		// if this is not the last row, then we draw "-+-+-"
		if (!(i == map.GetAmountRow() - 1))
		{
			std::cout << "-+-+-" << '\n';
		}
	}
}