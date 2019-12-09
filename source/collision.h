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
description: check if 2 circles collide with the each other.
return: bool
precondition: 2 circles exists and they are valid.
postcondition: return 1 if the circles intersect.
*/
bool circleIntersect(circle_t, circle_t);

/*
deprecated
*/
void collid(alien_group, vector<bullet_t>&, int, int, SDL_Plotter&);

/*
description: Check collision of player's bullet against aliens
return: none
precondition: alien_group exists, player has fired a bullet
postcondition: If bullet hits an alien, it kills the bullet and alien.
               Otherwise, it keeps going until end of screen.
*/
void collid2KillAlien(alien_group&, vector<bullet_t>&, SDL_Plotter&);

/*
description: Check collision of aliens' bullets against player
return: none
precondition: alien_group exists, player has fired a bullet
postcondition: If bullet hits player, it kills the bullet and damages player.
               Otherwise, it keeps going until end of screen.
*/
void collid2KillPlayer(player&, vector<bullet_t>&, SDL_Plotter&);

#endif
