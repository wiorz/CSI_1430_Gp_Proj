#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "rectangle.h"
#include "color.h"
#include "SDL_Plotter.h"

const int UNITSIZE = 20;
const int WIDTH = 1080;
const int HEIGHT = 720;
const int DEFAULTSTEP = 5;

class player
{
    private:
        rectangle_t body, head; // A player is made of 2 rectangles.
        int step; // Default to fixed speed of 5.
        color normal; // Default to the color green.
        color cleared; // Background is black.

    public:
        player();
        player(const rectangle_t&); // Only allows setting of the body rectangle.
        player(const rectangle_t&, int = DEFAULTSTEP);
        player(const rectangle_t&, int = DEFAULTSTEP, color = GREENCOLOR,
               color = BLACKCOLOR);

        // Mutators
        void setBodyRectangle(const rectangle_t&);
        void setStep(const int); // This should not be called.
        void setNormalColor(const color);
        void setClearedColor(const color);

        // Getters
        rectangle_t getBodyRectangle() const;
        rectangle_t getHeadRectangle() const;
        int getStep() const;
        color getNormalColor() const;
        color getClearedColor() const;

        // Display helpers
        void draw(SDL_Plotter& g, ostream&) const;
        void undraw(SDL_Plotter& g) const;

        // Actions
        void movePlayerByNSteps(const int);
        void fire(); // TODO maybe change this to return a bullet object?
        // bomb? power up? shield? HP?

};

#endif // PLAYER_H_INCLUDED
