#ifndef collision
#define collision
#include "SDL_Plotter.h"
#include "alien.h"
#include "point.h"
#include "color.h"
#include "bullet.h"
#include <cmath>

void collid(vector<alien_t>&, vector<bullet_t>&, int, int);

void collid(vector<alien_t>& v, vector<bullet_t>& b, int n, int bulla) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < bulla; j++) {
			cout << i << ": " << abs(v[i].getCenterPos().x - b[j].getCenter().x)
				 << " " << v[i].getRadius() + b[j].getR();
			if (abs(v[i].getCenterPos.x - b[j].getCenter().x)
					< v[i].getRadius() + b[j].getR()) {
				v[i].setNormalColor(WHITECOLOR);
				v[i].kill();
			}
		}
	}
}
#endif
