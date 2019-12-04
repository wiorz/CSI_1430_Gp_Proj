#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "rectangle.h"
#include "color.h"
#include "SDL_Plotter.h"

const int UNITSIZE = 20;
const int WIDTH = 1080;
const int HEIGHT = 720;
const int DEFAULTSTEP = 10;

class player
{
    private:
        rectangle_t body, head; // A player is made of 2 rectangles.
        int step; // Default to fixed speed of 10.
        color normal; // Default to the color green.
        color cleared; // Background is black.

    public:
        player();

        /*Use this constructor. It reads from settings in main and get
          speed from main, instead of having to use separate values here.
        */
        player(SDL_Plotter& g, int);

        // Only allows setting of the body rectangle.
        player(const rectangle_t&);
        player(const rectangle_t&, int = DEFAULTSTEP);
        player(const rectangle_t&, int = DEFAULTSTEP, color = GREENCOLOR,
               color = BLACKCOLOR);

        // ---Mutators---

        // Set the body rectangle, the head will be automatically adjusted.
        void setBodyRectangle(const rectangle_t&);

        // Change the speed of player.
        // This should not be called, the game is developed for fixed speed.
        void setStep(const int);

        // Set the base draw color.
        void setNormalColor(const color);

        // Set the color that "erase" the player by setting it to the
        // background color.
        void setClearedColor(const color);

        // ---Getters---

        rectangle_t getBodyRectangle() const;
        rectangle_t getHeadRectangle() const;
        int getStep() const;
        color getNormalColor() const;
        color getClearedColor() const;

        // ---Display helpers---

        /*
        Draw the player onto the plot. THe color is based on the normal color.
        */
        void draw(SDL_Plotter& g) const;

        /*
        "Clear" the player from the plot by setting it to background color,
        which is based on "cleared" color.
        */
        void undraw(SDL_Plotter& g) const;

        // Actions

        /*
        Steps is controlled by the step size. So if step size is 10, then
        a +1 step means one step to right, -1 means one step to left.
        */
        void movePlayerByNSteps(const int);

        // TODO maybe change this to return a bullet object?
        // bomb? power up? shield? HP?
        void fire();

};

#endif // PLAYER_H_INCLUDED
