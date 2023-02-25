#pragma once

#ifndef _MAP_
#define _MAP_

typedef unsigned short u_short;

namespace map_mdl
{
	class Map
	{
	public:
		Map();
		~Map() = default;
		Map(const Map& other) = delete;

		char& GetElement(const u_short row, const u_short column);
		void SetElement(const u_short row, const u_short column, char symbol);

		u_short GetRow() const;
		u_short GetColumn() const;

	private:
		u_short m_ROW;
		u_short m_COLUMN;

		char m_map[3][5];
	};
}

#endif // _MAP_