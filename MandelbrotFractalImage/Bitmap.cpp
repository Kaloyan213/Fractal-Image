#include "Bitmap.h"

namespace bitmap {
	Bitmap::Bitmap(int width, int height) :_width(width ), _height( height ),
		_pixels{ new uint8_t[width * height * 3]() } {};

	bool Bitmap::write(std::string fileName) {
		bitmap::BitmapFileHeader fileHeader;
		bitmap::BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) +
			(_width * _height * 3);
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.height = _height;
		infoHeader.width = _width;

		std::ofstream file;
		file.open(fileName, std::ios::binary);

		if (!file.is_open()) {
			return 0;
		}

		file.write((char*)&fileHeader, sizeof(fileHeader));
		file.write((char*)&infoHeader, sizeof(infoHeader));
		file.write((char*)_pixels.get(), _width * _height * 3);

		file.close();
		if (file.is_open()) {
			return 0;
		}

		return 1;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		uint8_t* pPixel = _pixels.get();

		pPixel += y * _width * 3 + x * 3;

		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}
}
