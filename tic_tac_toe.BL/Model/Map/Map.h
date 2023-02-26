#pragma once

#ifndef _MAP_H_
#define _MAP_H_

typedef unsigned short u_short;

namespace model
{
	namespace map
	{
		class Map
		{
		public:
			Map();
			~Map() = default;
			Map(const Map& other) = delete;

			char GetElement(const u_short row, const u_short column) const;
			void SetElement(const u_short column, const u_short row, char symbol);

			u_short GetAmountRow() const;
			u_short GetAmountColumn() const;

		private:
			u_short m_ROW;
			u_short m_COLUMN;

			char m_map[3][3];
		};
	}
}

#endif // _MAP_H_