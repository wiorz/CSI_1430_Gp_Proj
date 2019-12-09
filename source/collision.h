#ifndef collision
#define collision
#include "SDL_Plotter.h"
#include "alien.h"
#include "alien_group.h"
#include "point.h"
#include "color.h"
#include "bullet.h"
#include <cmath>

void collid(vector<alien_group>&, vector<bullet_t>&, int, int, SDL_Plotter&);

void collid(vector<alien_group>& v, vector<bullet_t>& b, int n, int bullA, SDL_Plotter& g) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < bullA; j++) {
			cout << i << ": " << abs(v[i].getCenterPos().x - b[j].getCenter().x)
				 << " " << v[i].getRadius() + b[j].getR();
			if (abs(v[i].getCenterPos.x - b[j].getCenter().x)
					< v[i].getRadius() + b[j].getR()) {
				v[i].removeAlienAtIndex(i);
				g.initSound("clear.wav");
				g.playSound("clear.wav");
			}
		}
	}
}
#endif
