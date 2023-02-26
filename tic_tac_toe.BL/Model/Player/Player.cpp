#include "Player.h"

namespace model
{
	namespace player
	{
		Player::Player() :
			m_player('0')
		{ }

		char Player::GetPlayer() const
		{
			return m_player;
		}

		void Player::SetPlayer(const char player)
		{
			m_player = player;
		}
	}
}