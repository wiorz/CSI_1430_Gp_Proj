#include "alien.h"

alien_t::alien_t()
{
    centerPos = point(10, 10);
    radius = 15.0;
    normal = GREENCOLOR;
    cleared = BLACKCOLOR;
    step = 10;
    isAlive = true;
    hitBox.setCenter(centerPos);
    hitBox.setRadius(radius);
    hitBox.setColor(normal);
    totalCount++;
}

alien_t::alien_t(point p, int stepSize):centerPos(p), step(stepSize)
{
    radius = 15.0;
    normal = GREENCOLOR;
    cleared = BLACKCOLOR;
    isAlive = true;
    hitBox.setCenter(centerPos);
    hitBox.setRadius(radius);
    hitBox.setColor(normal);
    totalCount++;
}

int alien_t::totalCount = 0;

void alien_t::setCenterPos(point p)
{
    centerPos = p;
    hitBox.setCenter(centerPos);
}

void alien_t::setRadius(double r)
{
    radius = r;
}

void alien_t::setStepSize(int s)
{
    step = s;
}

void alien_t::setNormalColor(color n)
{
    normal = n;
}

void alien_t::setClearedColor(color c)
{
    cleared = c;
}

void alien_t::makeAlive()
{
    if(!isAlive)
    {
        isAlive = true;
        totalCount++;
    }
}


void alien_t::kill()
{
    if(isAlive)
    {
        isAlive = false;
        totalCount--;
    }
}

void alien_t::moveByNStepsInXCoord(int numSteps)
{
    centerPos.x += numSteps * step;
    hitBox.setCenter(centerPos);
}

void alien_t::moveByNStepsInYCoord(int numSteps)
{
    centerPos.y += numSteps * step;
    hitBox.setCenter(centerPos);
}

point alien_t::getCenterPos() const
{
    return centerPos;
}

double alien_t::getRadius() const
{
    return radius;
}

int alien_t::getStepSize()const
{
    return step;
}

color alien_t::getNormalColor() const
{
    return normal;
}

color alien_t::getClearedColor() const
{
    return cleared;
}

bool alien_t::getIsAlive() const
{
    return isAlive;
}

circle_t alien_t::getHitBox() const
{
    return hitBox;
}

// TODO: draw base on something else, NOT from hitbox.
void alien_t::undraw(SDL_Plotter& g)
{
    hitBox.setColor(cleared);
    hitBox.draw(g);
}

void alien_t::draw(SDL_Plotter& g)
{
    if(isAlive)
    {
        hitBox.setColor(normal);
        hitBox.draw(g);
    } else
    {
        undraw(g);
    }

}

void alien_t::fire(vector<bullet_t>& btVec)
{
    if(btVec.size() < 3)
    {
        int ypos = centerPos.y + radius;
        btVec.push_back(bullet_t(point(centerPos.x, ypos),
                                 radius / 3, 1));
    }

}
