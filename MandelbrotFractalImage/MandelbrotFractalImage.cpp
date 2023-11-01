#include <iostream>
#include "Bitmap.h"

int main() {
	int width = 1920;
	int height = 1080;

	bitmap::Bitmap bitmap(width, height);

	for (size_t y = 0; y < height; y++){
		for (size_t x = 0; x < width; x++)
		{
			bitmap.setPixel(x, y, 250, 100, 150);
		}
	}

	bitmap.write("test.bmp");

	std::cout << "Finished!" << std::endl;
}