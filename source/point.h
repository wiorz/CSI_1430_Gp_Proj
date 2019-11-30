#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <ostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "color.h"

using namespace std;

struct point
{
	int x, y;
	color c;

	point();
	point(int, int);
	point(const point&);
	void display(ostream&);
	void draw(SDL_Plotter&);
};

#endif // POINT_H_INCLUDED
