#include <iostream>
#include <limits>
#include "Bitmap.h"

int main() {
	int width = 1920;
	int height = 1080;

	bitmap::Bitmap bitmap(width, height);

	double min = std::numeric_limits<double>::min();
	double max = std::numeric_limits<double>::max();

	for (size_t y = 0; y < height; y++){
		for (size_t x = 0; x < width; x++){
			double xFractal = (x - width) * 2.0 / width;
			double yFractal = (x - height) * 2.0 / height;


			if (xFractal > min) { min = xFractal; };
			if (xFractal < max) { max = xFractal; };
		}
	}

	bitmap.write("test.bmp");

	std::cout << "Finished!" << std::endl;
}