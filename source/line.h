#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <cassert>
#include "point.h"
#include "color.h"

using namespace std;

class line
{
    private:
        point p1, p2;
        color c;

    public:
        // Initialize position and color.
        line(point = point (0, 0), point = point(1, 1), color = BLACKCOLOR);
        // The slope already has the points.
        // Just need to pass in the value for changing.
        bool slope(double& m) const;
        double y_intercept() const;
        void display(ostream&);
        void draw(SDL_Plotter&);

        // Mutators
        void setPointOne(const point);
        void setPointTwo(const point);
        void setColor(const color);

        // Getters
        point getPointOne() const;
        point getPointTwo() const;
        color getColor() const;

};

#endif // LINE_H_INCLUDED
