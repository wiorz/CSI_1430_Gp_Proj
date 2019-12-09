#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED

#include "point.h"
#include "color.h"
#include "circle.h"
#include "SDL_Plotter.h"

const double DEFAULTUNITSIZE = 15;

class alien_t
{
    private:
        point centerPos;
        double radius;
        int step;
        color normal;
        color cleared;
        bool isAlive;
        circle_t hitBox;

    public:
        alien_t();

        /*
        Use this as default constructor.
        Sends in a point for center, and int for speed.
        Everything else should be handled automatically.
        */
        alien_t(point, int);

        // ---Static members---

        // Useful to see total number
        static int totalCount;

        // ---Mutators---

        void setCenterPos(point);
        void setRadius(double);
        void setStepSize(int);
        void setNormalColor(color);
        void setClearedColor(color);

        /*
        Necromancy is prohibited! Created for testing only.
        Note: also increment totalCount, based on the assumption that kill
        has decremented totalCount.
        */
        void makeAlive();

        /*
        Kill it ded.
        Should also decrement totalCount besides invoking undraw().
        The alien still "exists" but cannot be hit.
        The alienGroup will be responsible for removing the dead alien.
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


        point getCenterPos() const;
        double getRadius() const;
        int getStepSize()const;
        color getNormalColor() const;
        color getClearedColor() const;
        bool getIsAlive() const;
        circle_t getHitBox() const;

        // ---Display helpers---
        void undraw(SDL_Plotter&);
        void draw(SDL_Plotter&);

};

#endif // ALIEN_H_INCLUDED
