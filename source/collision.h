#ifndef collision
#define collision
#include "SDL_Plotter.h"
#include "alien.h"
#include "alien_group.h"
#include "point.h"
#include "color.h"
#include "bullet.h"
#include <cmath>
#include <ostream>

bool circleIntersect(circle_t, circle_t);

bool circleIntersect(circle_t c1, circle_t c2)
{
    int distSq = (c1.getCenter().x - c2.getCenter().x) *
                 (c1.getCenter().x - c2.getCenter().x) +
                 (c1.getCenter().y - c2.getCenter().y) *
                 (c1.getCenter().y - c2.getCenter().y);
    int radSumSq = (c1.getRadius() + c2.getRadius()) *
                   (c1.getRadius() + c2.getRadius());

    return (distSq < radSumSq);
}

void collid(alien_group, vector<bullet_t>&, int, int, SDL_Plotter&);

void collid(alien_group v, vector<bullet_t>& b, int n, int bullA,
            SDL_Plotter& g) {
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

void collid2KillAlien(alien_group&, vector<bullet_t>&, SDL_Plotter&);

void collid2KillAlien(alien_group& aG, vector<bullet_t>& btVec, SDL_Plotter& g)
{
    if(btVec.size())
    {
        if(aG.getAlienGroupSize())
        {

            for(unsigned int j = 0; j < aG.getAlienGroupSize(); j++)
            {
                if (btVec.at(0).getIsAlive() == false)
                {
                    //os << "dead bullet" << endl;
                    break;
                }
                if (circleIntersect(aG.getAlienAtIndex(j).getHitBox(),
                                    btVec.at(0).getHitBox()))
                {
                    //os << "hit" << endl;
                    g.playSound("clear.wav");
                    aG.removeAlienAtIndex(g, j);
                    btVec.at(0).kill();
                }
            }
            if(!btVec.at(0).getIsAlive())
            {
                btVec.at(0).killAndRemoveFromBTVector(btVec, 0);
            }
        }
    }
}

void collid2KillPlayer(player&, vector<bullet_t>&, SDL_Plotter&);

void collid2KillPlayer(player& p, vector<bullet_t>& btVec, SDL_Plotter& g)
{
    int index;
    bool isHit = false;
    if(btVec.size())
    {

        for(unsigned int i = 0; i < btVec.size(); i++)
        {
            if (btVec.at(i).getIsAlive() == false)
            {
                //os << "dead bullet" << endl;
                break;
            }

            if (circleIntersect(p.getHitBox(), btVec.at(i).getHitBox()))
            {
                p.hurt();
                btVec.at(i).kill();
                index = i;
                isHit = true;
                g.playSound("bleeeat.wav");
            }
        }

    }

    if(isHit)
    {
        btVec.at(index).killAndRemoveFromBTVector(btVec, index);
    }
}
#endif
