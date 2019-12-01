#ifndef RECTANGLE_T_H_INCLUDED
#define RECTANGLE_T_H_INCLUDED

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"

class rectangle_t
{
    private:
        point upperL, lowerR;
        color c;

    public:
        rectangle_t();
        rectangle_t(point, point, color = REDCOLOR);
        rectangle_t(const rectangle_t&);

        void setUpperLeft(const point);
        void setLowerRight(const point);
        void setColor(const color);

        point getUpperLeft() const;
        point getLowerRight() const;
        color getColor() const;

        void draw(SDL_Plotter& g) const;
};

#endif // RECTANGLE_T_H_INCLUDED
