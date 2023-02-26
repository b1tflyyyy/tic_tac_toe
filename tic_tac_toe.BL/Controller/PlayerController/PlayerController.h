#pragma once

#ifndef _PlayerController_H_
#define _PlayerController_H_

#include "../../Model/Player/Player.h"

namespace controller
{
	namespace player
	{
		class PlayerController
		{
		public:
			PlayerController() = default;
			~PlayerController() = default;
			PlayerController(const PlayerController& other) = delete;

			void ChangePlayer(model::player::Player& player);
		};
	}
}

#endif // _PlayerController_H_
