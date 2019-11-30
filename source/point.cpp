#include "point.h"
#include "SDL_Plotter.h"

point::point()
{
	x = y = 0; // No need to instantiate, just initialize. Global object scope.
	c = BLACK;

}

point::point(int a, int b)
{
	x = a;
	y = b;
	c = BLACK;

}

point::point(const point& p)
{
	x = p.x;
	y = p.y;
	c = p.c;
}

// point:: tells the compiler to not to use a generic draw().
void point::draw(SDL_Plotter& g)
{

	g.plotPixel(x, y, 0, 0, 0);
}

void point::display(ostream& os)
{
	os << "(" << x << "," << y << ")";
}
