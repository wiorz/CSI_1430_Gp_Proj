#include "bullet.h"

bullet_t::bullet_t(point p, double hbSize, int n): centerTopPos(p),
                                                   hbRadius(hbSize), step(n)
{
    normal = WHITECOLOR;
    cleared = BLACKCOLOR;
    isAlive = true;
    hitBox.setCenter(point(centerTopPos.x, centerTopPos.y - hbRadius));
    hitBox.setRadius(hbRadius);
    hitBox.setColor(normal);
    setShapeFromPoint(centerTopPos);
    shape.setColor(normal);

}

void bullet_t::setCenterTopPos(point p)
{
    centerTopPos = p;
}

void bullet_t::setHBRadius(double r)
{
    hbRadius = r;
}

void bullet_t::setStepSize(int n)
{
    step = n;
}

void bullet_t::setNormalColor(color c)
{
    normal = c;
}

void bullet_t::setClearedColor(color c)
{
    cleared = c;
}

void bullet_t::setShapeFromPoint(point p)
{
    shape.setUpperLeft(point(p.x - hbRadius /2, p.y));
    shape.setLowerRight(point(p.x + hbRadius /2, p.y + hbRadius * 2.5));
}

void bullet_t::kill()
{
    isAlive = false;
}

void bullet_t::killAndRemoveFromBTVector(vector<bullet_t>& btVec,
                                         const int index)
{
    if(btVec.size())
    {
        btVec.at(index).kill();
        btVec.erase(btVec.begin() + index);
    }
}

void bullet_t::moveByNStepsInXCoord(int numSteps)
{
    centerTopPos.x += numSteps * step;
    hitBox.setCenter(point(centerTopPos.x, centerTopPos.y));
    setShapeFromPoint(centerTopPos);
}

void bullet_t::moveByNStepsInYCoord(int numSteps)
{
    centerTopPos.y += numSteps * step;
    hitBox.setCenter(point(centerTopPos.x, centerTopPos.y));
    setShapeFromPoint(centerTopPos);
}

point bullet_t::getCenterTopPos() const
{
    return centerTopPos;
}

double bullet_t::getHBRadius() const
{
    return hbRadius;
}

int bullet_t::getStepSize()const
{
    return step;
}

color bullet_t::getNormalColor() const
{
    return normal;
}

color bullet_t::getClearedColor() const
{
    return cleared;
}

bool bullet_t::getIsAlive() const
{
    return isAlive;
}

circle_t bullet_t::getHitBox() const
{
    return hitBox;
}

rectangle_t bullet_t::getShape() const
{
    return shape;
}

void bullet_t::undraw(SDL_Plotter& g)
{
    shape.setColor(cleared);
    shape.draw(g);
}
void bullet_t::draw(SDL_Plotter& g)
{
    shape.setColor(normal);
    shape.draw(g);
}
