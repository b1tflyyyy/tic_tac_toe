#include "MapController.h"

namespace controller
{
	namespace map
	{
		// TODO: Remove the ability to place the player in an existing place.

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

		bool MapController::IsPlayerWin(const model::map::Map& map,
										const model::player::Player& current_player)
		{
			if (VerticalCheck(map, current_player))
			{
				return true;
			}
			else if (HorizontalCheck(map, current_player))
			{
				return true;
			}
			else if (DiagonalCheckFromTopLeft(map, current_player))
			{
				return true;
			}
			else if (DiagonalCheckFromTopRight(map, current_player))
			{
				return true;
			}

			return false;
		}

		bool MapController::HorizontalCheck(const model::map::Map& map,
											const model::player::Player& current_player)
		{
			for (u_short i = 0; i < map.GetAmountRow(); i++)
			{
				if (map.GetElement(i, 0) == current_player.GetPlayer() &&
					map.GetElement(i, 1) == current_player.GetPlayer() &&
					map.GetElement(i, 2) == current_player.GetPlayer())
				{
					return true;
				}
			}

			return false;
		}

		bool MapController::VerticalCheck(const model::map::Map& map,
										  const model::player::Player& current_player)
		{
			for (u_short i = 0; i < map.GetAmountColumn(); i++)
			{
				if (map.GetElement(0, i) == current_player.GetPlayer() &&
					map.GetElement(1, i) == current_player.GetPlayer() &&
					map.GetElement(2, i) == current_player.GetPlayer())
				{
					return true;
				}
			}

			return false;
		}

		bool MapController::DiagonalCheckFromTopLeft(const model::map::Map& map,
													 const model::player::Player& current_player)
		{
			if (map.GetElement(0, 0) == current_player.GetPlayer() &&
				map.GetElement(1, 1) == current_player.GetPlayer() &&
				map.GetElement(2, 2) == current_player.GetPlayer())
			{
				return true;
			}

			return false;
		}

		bool MapController::DiagonalCheckFromTopRight(const model::map::Map& map,
													  const model::player::Player& current_player)
		{
			if (map.GetElement(0, 2) == current_player.GetPlayer() &&
				map.GetElement(1, 1) == current_player.GetPlayer() &&
				map.GetElement(2, 0) == current_player.GetPlayer())
			{
				return true;
			}

			return false;
		}
	}
}