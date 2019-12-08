#ifndef test
#define test

#include "player.h"
#include "SDL_Plotter.h"
#include "rectangle.h"
#include "point.h"
#include <vector>
#include <iostream>

using namespace std;

class bullet {
private:
	point p, p1;
	vector<point> b;
	rectangle_t rect;
	int count;
public:
	bullet();
	void countInc();
	void drawBullet(SDL_Plotter& g);
	void clearBullet(SDL_Plotter& g);

};

#endif
