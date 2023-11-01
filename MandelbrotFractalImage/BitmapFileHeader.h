#pragma once
#include <array>

#pragma pack(2)
namespace bitmap {
	struct BitmapFileHeader {
		std::array<char, 2> header{ 'B', 'M' };
		uint32_t fileSize;
		uint32_t reserved{ 0 };
		uint32_t dataOffset;

	};
}
