#pragma once

namespace bitmap {
	class Mandelbrot
	{
	public:

		static const int MAX_ITERATIONS = 1000;

		static int getIterations(double x, double y);
	};
}

