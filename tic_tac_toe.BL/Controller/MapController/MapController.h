#pragma once

#ifndef _MapController_H_
#define _MapController_H_

#include "..//..//Model/Map/Map.h"
#include "..//..//Model/Player/Player.h"

// TODO: add new function -> MapClear

typedef unsigned short u_short;

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
								const u_short x, 
								const u_short y, 
								const model::player::Player& player);

			// rename it
			bool IsPlayerWin(const model::map::Map& map,
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
				             const u_short y,
							 const u_short x);
		};
	}
}

#endif // _MapController_H_