#include <iostream>
#include <limits>
#include "Bitmap.h"
#include "Mandelbrot.h"

int main() {
	int width = 1080;
	int height = 1080;

	bitmap::Bitmap bitmap(width, height);

	double min = 999999;
	double max = -99999;

	for (int y = 0; y < height; y++){
		for (int x = 1; x < width; x++){
			double xFractal = (x - width/2) * 2.0 / width;
			double yFractal = (y - height/2) * 2.0 / height;
				
			int iterations = bitmap::Mandelbrot::getIterations(xFractal, yFractal);
			uint8_t red = (uint8_t)(256 * (double)iterations/bitmap::Mandelbrot::MAX_ITERATIONS);

			bitmap.setPixel(x, y, red, 0, 0);
			if (red < min) { min = red; };
			if (red > max) { max = red; };
		}
	}
	std::cout << min << ", " << max << "\n";


	bitmap.write("test.bmp");

	std::cout << "Finished!" << std::endl;
}