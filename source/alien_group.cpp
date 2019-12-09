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

void alien_group::moveAliensByNSteps(SDL_Plotter& g, const int val)
{
    int currXPosLeft;
    int currXPosRight;
    bool changedDirection = false;
    point currCenter;

    for(unsigned int i = 0; i < aliens.size() && !changedDirection; i++)
    {
        // Check if an alien reaches left boundary
        currCenter = aliens.at(i).getCenterPos();
        currXPosLeft = currCenter.x - aliens.at(i).getRadius();
        currXPosRight = currCenter.x + aliens.at(i).getRadius();
        if(currXPosLeft <= 0 || currXPosRight >= g.getCol())
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
            aliens.at(i).moveByNStepsInYCoord(val * 2.5);
        }

        aliens.at(i).moveByNStepsInXCoord(val * direction);
    }
}

void alien_group::removeAlienAtIndex(const int index)
{
    aliens.erase(aliens.begin() + index);
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
