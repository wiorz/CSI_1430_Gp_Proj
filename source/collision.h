#ifndef collision
#define collision
#include "SDL_Plotter.h"
#include "alien.h"
#include "alien_group.h"
#include "point.h"
#include "color.h"
#include "bullet.h"
#include <cmath>

void collid(alien_group, vector<bullet_t>&, int, int, SDL_Plotter&);

void collid(alien_group v, vector<bullet_t>& b, int n, int bullA, SDL_Plotter& g) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < bullA; j++) {
			if (b[j].getIsAlive() == false)
				break;
			if (abs(v.getAlienAtIndex(i).getCenterPos().x -
					b[j].getCenterTopPos().x)
					< v.getAlienAtIndex(i).getRadius() + b[j].getHBRadius())
				v.removeAlienAtIndex(g, i);
		}
	}
}
#endif
