#include <iostream>
#include "../tic_tac_toe.BL/Model/Map/Map.h"
#include "../tic_tac_toe.BL/Controller/MapController/MapController.h"

void Print(model::map::Map& map);


int main()
{
	model::map::Map map;
	controller::map::MapController mapController;

	mapController.SetPlayerOnMap(map, 2, 0, '0');
	Print(map);

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