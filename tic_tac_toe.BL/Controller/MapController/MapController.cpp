#include "MapController.h"

namespace map_ctrl
{
	void MapController::Print(map_mdl::Map& map) const
	{
		system("cls");

		for (u_short i = 0; i < map.GetRow(); i++)
		{
			for (u_short j = 0; j < map.GetColumn(); j++)
			{
				std::cout << map.GetElement(i, j);
			}
			std::cout << '\n';
		}
	}

	void MapController::SetPlayerOnMap(map_mdl::Map& map, const u_short x, const u_short y, const char player)
	{
		map.SetElement(y, x, player);
	}
}