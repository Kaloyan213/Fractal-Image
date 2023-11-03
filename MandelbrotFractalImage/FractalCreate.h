#pragma once
#include <string>
#include "Zoom.h"
class FractalCreate{
public:
	FractalCreate(int width, int height);
	void calculateIterations();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmap(std::string name);
};

