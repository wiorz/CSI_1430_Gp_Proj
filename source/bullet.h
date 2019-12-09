#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "point.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"

class bullet_t
{
    private:
        point centerTopPos;
        double hbRadius;
        int step;
        color normal;
        color cleared;
        bool isAlive;
        circle_t hitBox;
        rectangle_t shape;

    public:
        /*
        Use this as default constructor.
        Sends in a point for center, and int for speed.
        Everything else should be handled automatically.
        */
        bullet_t(point, double, int);

        // ---Mutators---

        void setCenterTopPos(point);
        void setHBRadius(double);
        void setStepSize(int);
        void setNormalColor(color);
        void setClearedColor(color);
        void setShapeFromPoint(point);

        /*
        Kill it.
        */
        void kill();

        /*
        Offset center position by n steps.
        +1 means move one step to right.
        -1 means move one step to left.
        */
        void moveByNStepsInXCoord(int);
        /*
        Offset center position by n steps.
        +1 means move one step downwards to bottom.
        -1 means move one step upwards.
        */
        void moveByNStepsInYCoord(int);

        // --- Getters---


        point getCenterTopPos() const;
        double getHBRadius() const;
        int getStepSize()const;
        color getNormalColor() const;
        color getClearedColor() const;
        bool getIsAlive() const;
        circle_t getHitBox() const;
        rectangle_t getShape() const;

        // ---Display helpers---
        void undraw(SDL_Plotter&);
        void draw(SDL_Plotter&);
};


#endif // BULLET_H_INCLUDED
