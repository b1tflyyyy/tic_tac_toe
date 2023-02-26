#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

namespace model
{
	namespace player
	{
		class Player
		{
		public:
			Player();
			~Player() = default;
			Player(const Player& other) = delete;

			char GetPlayer() const;
			void SetPlayer(const char player);

		private:
			char m_player;
		};
	}
}

#endif // _PLAYER_H_
