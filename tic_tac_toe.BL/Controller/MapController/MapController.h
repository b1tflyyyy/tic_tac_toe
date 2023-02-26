#pragma once

#ifndef _MapController_
#define _MapController_

#include "..//..//Model/Map/Map.h"

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
								const char player);
		};
	}
}

#endif