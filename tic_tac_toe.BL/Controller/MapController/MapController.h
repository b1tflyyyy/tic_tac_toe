#pragma once

#ifndef _MapController_H_
#define _MapController_H_

#include "..//..//Model/Map/Map.h"
#include "..//..//Model/Player/Player.h"

#include <iostream>


namespace controller
{
	namespace map
	{
		class MapController
		{
		public:
			MapController() = default;
			~MapController() = default;
			MapController(const MapController& other) = delete;

			bool SetPlayerOnMap(model::map::Map& map, 
								const std::uint16_t x,
								const std::uint16_t y,
								const model::player::Player& player);

			// rename it
			bool IsWinCombination(const model::map::Map& map,
							 const model::player::Player& current_player);

			void ClearMap(model::map::Map& map);

		private:
			bool HorizontalCheck(const model::map::Map& map,
				                 const model::player::Player& current_player);
			
			bool VerticalCheck(const model::map::Map& map,
							   const model::player::Player& current_player);

			bool DiagonalCheckFromTopLeft(const model::map::Map& map,
										  const model::player::Player& current_player);
			
			bool DiagonalCheckFromTopRight(const model::map::Map& map,
										   const model::player::Player& current_player);

			bool IsCellEmpty(const model::map::Map& map,
				             const std::uint16_t y,
							 const std::uint16_t x);
		};
	}
}

#endif // _MapController_H_