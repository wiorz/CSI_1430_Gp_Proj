// 11/18/2019 Mon

#include "circle.h"

circle_t::circle_t()
{
    radius = 1.0;
    center = point(0, 0);
    c      = REDCOLOR;
}

circle_t::circle_t(double rIn, point centerIn, color colorIn)
{
    radius = rIn;
    center = centerIn;
    c      = colorIn;
}

circle_t::circle_t(const circle_t& oC)
{
    radius = oC.radius;
    center = oC.center;
    c      = oC.c;
}

void circle_t::setRadius(double rIn)
{
    radius = rIn;
}

void circle_t::setCenter(point centerIn)
{
    center = centerIn;
}

void circle_t::setColor(color colorIn)
{
    c = colorIn;
}

double circle_t::getRadius() const
{
    return radius;
}

point circle_t::getCenter() const
{
    return center;
}

color circle_t::getColor() const
{
    return c;
}


void circle_t::draw(SDL_Plotter& g)
{
    // Draw circle that is inside a rectangle, upper left corner.
    for(int y = center.y - radius; y <= center.y + radius; y++)
    {
        for(int x = center.x - radius; x <= center.x + radius; x++)
        {
            // g.plotPixel(x, y, c.R, c.G, c.B); this will only give us a a rectangle
            // The first if is checking whether the point is in the circle
            if(sqrt(pow(center.x - x, 2) + pow(center.y - y, 2)) <= radius)
            {
                // THis if checks if the dot is on screen.
                if(x >= 0 && y >= 0 && x < g.getCol() && y < g.getRow())
                {
                    g.plotPixel(x, y, c.R, c.G, c.B);
                }
            }
        }
    }
}

