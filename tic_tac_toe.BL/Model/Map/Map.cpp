#include "Map.h"

namespace model
{
	namespace map
	{
		Map::Map() :
			m_ROW(3), m_COLUMN(3)
		{
			for (u_short i = 0; i < m_ROW; i++)
			{
				for (u_short j = 0; j < m_COLUMN; j++)
				{
					m_map[i][j] = ' ';
				}
			}
		}

		char& Map::GetElement(const u_short row, const u_short column)
		{
			return m_map[row][column];
		}

		void Map::SetElement(const u_short column, const u_short row, char symbol)
		{
			m_map[row][column] = symbol;
		}

		u_short Map::GetAmountRow() const
		{
			return m_ROW;
		}

		u_short Map::GetAmountColumn() const
		{
			return m_COLUMN;
		}
	}
}