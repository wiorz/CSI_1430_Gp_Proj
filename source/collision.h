#ifndef collision
#define collision
#include "SDL_Plotter.h"
#include "alien.h"
#include "alien_group.h"
#include "point.h"
#include "color.h"
#include "bullet.h"
#include "player.h"
#include <cmath>
#include <ostream>

/*

*/
bool circleIntersect(circle_t, circle_t);

void collid(alien_group, vector<bullet_t>&, int, int, SDL_Plotter&);

void collid2KillAlien(alien_group&, vector<bullet_t>&, SDL_Plotter&);

void collid2KillPlayer(player&, vector<bullet_t>&, SDL_Plotter&);

#endif
