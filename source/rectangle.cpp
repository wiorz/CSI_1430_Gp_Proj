#include "rectangle.h"

rectangle_t::rectangle_t()
{
    upperL.x = upperL.y = 0;
    // lowerR = point(1, 1); this is a lot of work
    lowerR.x = lowerR.y = 1;
    c = REDCOLOR;
}

rectangle_t::rectangle_t(point uL, point lR, color col)
{
    upperL = uL;
    lowerR = lR;
    c = col;
}

rectangle_t::rectangle_t(const rectangle_t& other)
{
    upperL = other.upperL; // Members of the same calss can see each other's private data.
    lowerR = other.lowerR;
    c = other.c;
}

void rectangle_t::setUpperLeft(const point p)
{
    upperL = p;
}

void rectangle_t::setLowerRight(const point p)
{
    lowerR = p;
}

void rectangle_t::setColor(const color a)
{
    c = a;
}

point rectangle_t::getUpperLeft() const
{
    return upperL;
}

point rectangle_t::getLowerRight() const
{
    return lowerR;
}

color rectangle_t::getColor() const
{
    return c;
}

void rectangle_t::draw(SDL_Plotter& g) const
{
    for(int y = min(upperL.y, lowerR.y); y < max(upperL.y, lowerR.y); y++)
    {
        for(int x = min(upperL.x, lowerR.x); x < max(upperL.x, lowerR.x); x++)
        {
            g.plotPixel(x, y, c.R, c.G, c.B);
        }
    }
}
