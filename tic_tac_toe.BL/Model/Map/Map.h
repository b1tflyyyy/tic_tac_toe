#pragma once

#ifndef _MAP_H_
#define _MAP_H_

#include <iostream>

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

			char GetElement(const std::uint16_t, const std::uint16_t column) const;
			void SetElement(const std::uint16_t column, const std::uint16_t row, char symbol);

			std::uint16_t GetAmountRow() const;
			std::uint16_t GetAmountColumn() const;

		private:
			std::uint16_t m_ROW;
			std::uint16_t m_COLUMN;

			char m_map[3][3];
		};
	}
}

#endif // _MAP_H_