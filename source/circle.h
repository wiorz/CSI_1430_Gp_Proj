#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

// UML:
// Circle
//      double radius
//      Point center
//      color C

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"

class circle_t
{
    private:
        double radius;
        point  center;
        color  c;

    public:
        circle_t();
        circle_t(double, point, color);
        circle_t(const circle_t&);

        void setRadius(double);
        void setCenter(point);
        void setColor(color);

        double getRadius() const;
        point getCenter() const;
        color getColor() const;

        void draw(SDL_Plotter&);

};

#endif // CIRCLE_H_INCLUDED
