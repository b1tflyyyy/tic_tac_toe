#include "Map.h"

namespace model
{
	namespace map
	{
		Map::Map() :
			m_ROW(3), m_COLUMN(3)
		{
			for (std::uint16_t i = 0; i < m_ROW; ++i)
			{
				for (std::uint16_t j = 0; j < m_COLUMN; ++j)
				{
					m_map[i][j] = ' ';
				}
			}
		}

		char Map::GetElement(const std::uint16_t row, const std::uint16_t column) const
		{
			return m_map[row][column];
		}

		void Map::SetElement(const std::uint16_t row, const std::uint16_t column, char symbol)
		{
			m_map[row][column] = symbol;
		}

		std::uint16_t Map::GetAmountRow() const
		{
			return m_ROW;
		}

		std::uint16_t Map::GetAmountColumn() const
		{
			return m_COLUMN;
		}
	}
}