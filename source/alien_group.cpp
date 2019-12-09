#include "alien_group.h"

alien_group::alien_group(SDL_Plotter& g, const int stepSize)
{
    // ALways start with going right.
    direction = 1;

    int xpos, ypos;
    for(int row = 0; row < DEFAULTROWSIZE; row++)
    {
        for(int col = 0; col < DEFAULTCOLSIZE; col++)
        {
            xpos = ((col - 5) * 50) + (g.getCol() / 2);
            ypos = (row * 40) + 50 ;
            aliens.push_back(alien_t(point(xpos, ypos), stepSize));
        }
    }
}

void alien_group::setDirection(const int val)
{
    direction = val;
}

vector<alien_t>& alien_group::getAlienGroupVect()
{
    return aliens;
}

unsigned int alien_group::getAlienGroupSize() const
{
    return aliens.size();
}

alien_t alien_group::getAlienAtIndex(const int index)
{
    return (aliens.at(index));
}

void alien_group::moveAliensByNSteps(SDL_Plotter& g, const int val)
{
    int currXPosLeft;
    int currXPosRight;
    bool changedDirection = false;
    double currRadius;
    point currCenter;

    for(unsigned int i = 0; i < aliens.size() && !changedDirection; i++)
    {
        // Check if an alien reaches left boundary
        currCenter = aliens.at(i).getCenterPos();
        currRadius = aliens.at(i).getRadius();
        currXPosLeft = currCenter.x - currRadius;
        currXPosRight = currCenter.x + currRadius;
        if(currXPosLeft - currRadius <= 0 ||
           currXPosRight + currRadius >= g.getCol())
        {
            direction *= -1; // Reverse direction
            changedDirection = true;
        }

    }

    for(unsigned int i = 0; i < aliens.size(); i++)
    {
        // Check if an alien reaches left boundary
        currCenter = aliens.at(i).getCenterPos();

        if(changedDirection)
        {
            aliens.at(i).moveByNStepsInYCoord(val * 3);
        }

        aliens.at(i).moveByNStepsInXCoord(val * direction);
    }
}

void alien_group::removeAlienAtIndex(SDL_Plotter& g, const int index)
{
    if(aliens.size())
    {
        aliens.at(index).kill();
        aliens.at(index).undraw(g);
        aliens.erase(aliens.begin() + index);
    }
}

void alien_group::fireAtIndex(vector<bullet_t>& btVec, const int agIndex)
{
    aliens.at(agIndex).fire(btVec);
}

void alien_group::draw(SDL_Plotter& g)
{
    for(unsigned int i = 0; i < aliens.size(); i++)
    {
        aliens.at(i).draw(g);
    }
}

void alien_group::undraw(SDL_Plotter& g)
{
    for(unsigned int i = 0; i < aliens.size(); i++)
    {
        aliens.at(i).undraw(g);
    }
}
