#include "Map.h"

namespace map_mdl
{
	Map::Map() :
		m_ROW(3), m_COLUMN(5)
	{
		for (u_short i = 0; i < m_ROW; i++)
		{
			for (u_short j = 0; j < m_COLUMN; j++)
			{
				if ((j + 1) % 2)
				{
					m_map[i][j] = ' ';
					continue;
				}

				m_map[i][j] = '|';
			}
		}
	}

	char& Map::GetElement(const u_short row, const u_short column)
	{
		return m_map[row][column];
	}

	void Map::SetElement(const u_short row, const u_short column, char symbol)
	{
		m_map[row][column] = symbol;
	}

	u_short Map::GetRow() const
	{
		return m_ROW;
	}

	u_short Map::GetColumn() const
	{
		return m_COLUMN;
	}
}