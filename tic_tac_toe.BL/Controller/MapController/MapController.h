#pragma once

#ifndef _MapController_
#define _MapController_

#include "..//..//Model/Map/Map.h"
#include <iostream>

typedef unsigned short u_short;

namespace map_ctrl
{
	class MapController
	{
	public:
		MapController() = default;
		~MapController() = default;
		MapController(const MapController& other) = delete;

		void Print(map_mdl::Map& map) const;
		void SetPlayerOnMap(map_mdl::Map& map, const u_short x, const u_short y, const char player);
	};
}

#endif