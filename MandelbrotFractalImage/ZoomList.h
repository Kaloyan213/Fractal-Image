#pragma once
#include<vector>
#include "Zoom.h"
class ZoomList
{
private:

	double _xCenter{ 0.0 };
	double _yCenter{ 0.0 };
	double _scale{ 1.0 };

	int _width{ 0 };
	int _height{ 0 };
	std::vector <Zoom> zooms;

public:
	ZoomList(int width, int height);

	void add(const Zoom& zoom);

	std::pair <double, double> doZoom(int x, int y);
};

