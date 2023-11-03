#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreate.h"

int main() {
	int width = 800;
	int height = 800;

	bitmap::Bitmap bitmap(width, height);

	double min = 999999;
	double max = -99999;

	ZoomList zoomList(width, height);

	zoomList.add(Zoom(width / 2, height / 2, 2.0/width));
	

	std::unique_ptr<int[]> histogram(new int [bitmap::Mandelbrot::MAX_ITERATIONS] {});
	std::unique_ptr<int[]> fractal(new int [width * height] {});

	for (int y = 0; y < height; y++) {
		for (int x = 1; x < width; x++) {
			std::pair <double, double> coordinates = zoomList.doZoom(x, y);

			int iterations = bitmap::Mandelbrot::getIterations(coordinates.first, coordinates.second);

			fractal[y * width + x] = iterations;

			if (iterations != bitmap::Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}


		}

		int total = 0;

		for (size_t i = 0; i < bitmap::Mandelbrot::MAX_ITERATIONS; i++) {
			total += histogram[i];
		}

		for (int y = 0; y < height; y++) {
			for (int x = 1; x < width; x++) {
				uint8_t red = 0;
				uint8_t green = 0;
				uint8_t blue = 0;
				int iterations = fractal[y * width + x];

				if (iterations != bitmap::Mandelbrot::MAX_ITERATIONS) {
					double hue = 0.0;

					for (size_t i = 0; i < iterations; i++) {
						hue += ((double)histogram[i]) / total;
					}

					green = pow(255, hue);

				}
				bitmap.setPixel(x, y, red, green, blue);
			}
		}
	}


	bitmap.write("test.bmp");

	std::cout << "Finished!" << std::endl;
}