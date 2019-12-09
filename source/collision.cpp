#include "collision.h"

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

void collid2KillAlien(alien_group& aG, vector<bullet_t>& btVec,
		SDL_Plotter& g, ostream& os)
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

void collid2KillPlayer(player& p, vector<bullet_t>& btVec,
		SDL_Plotter& g, ostream& os)
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
            }
        }

    }

    if(isHit)
    {
        btVec.at(index).killAndRemoveFromBTVector(btVec, index);
    }
}
