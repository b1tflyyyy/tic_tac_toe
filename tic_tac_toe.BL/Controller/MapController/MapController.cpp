#include "MapController.h"

namespace controller
{
	namespace map
	{
		bool MapController::SetPlayerOnMap(model::map::Map& map, 
										   const std::uint16_t x,
			                               const std::uint16_t y,
										   const model::player::Player& player)
		{
			if (x > map.GetAmountColumn() - 1 || 
				y > map.GetAmountRow() - 1 ||
				!IsCellEmpty(map, y, x))
			{
				return false;
			}

			map.SetElement(y, x, player.GetPlayer());
			return true;
		}

		bool MapController::IsWinCombination(const model::map::Map& map,
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
			for (std::uint16_t i = 0; i < map.GetAmountRow(); ++i)
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
			for (std::uint16_t i = 0; i < map.GetAmountColumn(); ++i)
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

		bool MapController::IsCellEmpty(const model::map::Map& map,
										const std::uint16_t y,
										const std::uint16_t x)
		{
			return map.GetElement(y, x) == ' ';
		}

		void MapController::ClearMap(model::map::Map& map)
		{
			for (std::uint16_t i = 0; i < map.GetAmountRow(); ++i)
			{
				for (std::uint16_t j = 0; j < map.GetAmountColumn(); ++j)
				{
					map.SetElement(i, j, ' ');
				}
			}
		}
	}
}