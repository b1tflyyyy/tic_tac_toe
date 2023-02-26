#include <iostream>

#include "../tic_tac_toe.BL/Model/Map/Map.h"
#include "../tic_tac_toe.BL/Controller/MapController/MapController.h"

#include "../tic_tac_toe.BL/Model/Player/Player.h"
#include "../tic_tac_toe.BL/Controller/PlayerController/PlayerController.h"

void Print(model::map::Map& map);


int main()
{
	model::map::Map map;
	model::player::Player player;

	controller::map::MapController mapController;
	controller::player::PlayerController playerController;

	mapController.SetPlayerOnMap(map, 0, 2, player.GetPlayer());
	mapController.SetPlayerOnMap(map, 0, 1, player.GetPlayer());
	
	playerController.ChangePlayer(player);
	
	mapController.SetPlayerOnMap(map, 0, 0, player.GetPlayer());
	mapController.SetPlayerOnMap(map, 1, 0, player.GetPlayer());
	mapController.SetPlayerOnMap(map, 2, 0, player.GetPlayer());
	
	Print(map);

	std::cout << mapController.IsPlayerWin(map, player) << '\n';

	return 0;
}


void Print(model::map::Map& map)
{
	system("cls");

	for (u_short i = 0; i < map.GetAmountRow(); i++)
	{
		for (u_short j = 0; j < map.GetAmountColumn(); j++)
		{
			std::cout << map.GetElement(i, j);

			if (!(j == map.GetAmountColumn() - 1))
			{
				std::cout << '|';
			}	
		}
	
		std::cout << '\n';
		if (!(i == map.GetAmountRow() - 1))
		{
			std::cout << "-+-+-" << '\n';
		}
	}
}