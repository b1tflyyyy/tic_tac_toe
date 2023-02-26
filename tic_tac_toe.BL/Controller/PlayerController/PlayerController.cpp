#include "PlayerController.h"

namespace controller
{
	namespace player
	{
		void PlayerController::ChangePlayer(model::player::Player& player)
		{
			if (player.GetPlayer() == '0')
			{
				player.SetPlayer('X');
				return;
			}
	
			player.SetPlayer('0');
		}
	}
}
