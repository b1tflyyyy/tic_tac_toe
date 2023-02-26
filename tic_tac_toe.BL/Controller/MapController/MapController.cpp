#include "MapController.h"

namespace controller
{
	namespace map
	{
		bool MapController::SetPlayerOnMap(model::map::Map& map, 
										   const u_short x, 
			                               const u_short y,  
										   const char player)
		{
			if (x > map.GetAmountColumn() - 1 || y > map.GetAmountRow() - 1)
			{
				return false;
			}

			map.SetElement(x, y, player);
			return true;
		}
	}
}