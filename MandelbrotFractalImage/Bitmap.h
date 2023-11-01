#pragma once
#include <string>
#include <memory>
#include <fstream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

namespace bitmap {
	class Bitmap {
	private:
		int _width{ 0 };
		int _height{ 0 };
		std::unique_ptr <uint8_t[]> _pixels{ nullptr };

	public:
		//Constructors
		Bitmap(int width, int height);

		//Member Methods
		bool write(std::string fileName);
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	};
}
