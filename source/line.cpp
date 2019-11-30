#include "line.h"

// NOTE: DO NOT repeat the default values.
line::line(point a, point b, color cr)
{
    p1 = a;
    p2 = b;
    c = cr;
}

// Mutators
void line::setPointOne(const point p)
{
    p1 = p;
}
void line::setPointTwo(const point p)
{
    p2 = p;
}
void line::setColor(const color clr)
{
    c = clr;
}

point line::getPointOne() const
{
    return p1;
}
point line::getPointTwo() const
{
    return p2;
}

color line::getColor() const
{
    return c;
}

bool line::slope(double& m) const
{
    bool hasSlope = false;

    hasSlope = (p1.x != p2.x);
    if(hasSlope)
    {
        m = static_cast<double>(p1.y - p2.y) / (p1.x - p2.x);
    }

    return hasSlope;

}

double line::y_intercept() const
{
    // Pre-condition - there's a slope.
    // y =mx +b
    // b = y- mx
    double m, b;
    if(slope(m))
    {
        b = p1.y - m * p1.x; // Can also use p2.
    }

    return b;
}

void line::display(ostream& os)
{
    // y = mx +b
    double m, b;
    if(slope(m))
    {
        b = y_intercept();
        os << "y = " << m << "x + " << b;
    } else
    {
        os << "x = " << p1.x; // If no slope, just print x.
    }


}

void line::draw(SDL_Plotter& g)
{
    double m, b, y;
    if(slope(m))
    {
        b = y_intercept();
        for(int x = min(p1.x, p2.x); x <= max(p1.x, p2.x); x++)
        {
            y = m * x + b;
            g.plotPixel(x, y, c.R, c.G, c.B);
        }
    }
}
