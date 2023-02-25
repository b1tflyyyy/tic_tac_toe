#include <iostream>
#include "../tic_tac_toe.BL/Model/Map/Map.h"
#include "../tic_tac_toe.BL/Controller/MapController/MapController.h"

int main()
{
	map_mdl::Map map;
	map_ctrl::MapController mapController;

	mapController.Print(map);
	mapController.SetPlayerOnMap(map, 0, 0, '0');
	
	mapController.Print(map);


	return 0;
}