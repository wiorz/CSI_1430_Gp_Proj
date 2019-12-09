#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include "rectangle.h"
#include "color.h"
#include "bullet.h"
#include "SDL_Plotter.h"
#include "alien.h"

const int UNITSIZE = 20;
const int WIDTH = 1080;
const int HEIGHT = 720;
const int DEFAULTSTEP = 10;
const int DEFAULTHP = 2;


class player
{
    private:
        rectangle_t body, head; // A player is made of 2 rectangles.
        int step; // Default to fixed speed of 10.
        color normal; // Default to the color green.
        color cleared; // Background is black.
        int hp;
        circle_t hitBox;

    public:
        /*
        description: constructor
        return: player
        precondition: none
        postcondition: created player object
        */
        player();

        /*
        description: constructor base on plotter size and custom speed
        return: player
        precondition: the plotter exists and the speed value is valid
        postcondition: created player object with relative values.
        */
        player(SDL_Plotter& g, int);

        // ---Mutators---

        /*
        description: Set the body rectangle base on another rectangle, the head
                     will be automatically adjusted.
        return: none
        precondition: the input rectangle exists and is valid
        postcondition: the body rectangle is same as the param.
        */
        void setBodyRectangle(const rectangle_t&);

        /*
        description: Change the speed of the player
                     Note: this should not be called.
        return: none
        precondition: input is valid
        postcondition: speed is changed correctly.
        */
        void setStep(const int);

        /*
        description: Set normal color to the input color
        return: none
        precondition: input is a valid color
        postcondition: normal is changed.
        */
        void setNormalColor(const color);

        /*
        description: Set the color that "erase" the player by setting it to
                     the background color.
        return: none
        precondition: input is a valid color
        postcondition: cleared is changed.
        */
        void setClearedColor(const color);

        // ---Getters---

        /*
        description: Get the body rectangle.
        return: rectangle_t
        precondition: body rectangle exists.
        postcondition: the body rectangle is returned.
        */
        rectangle_t getBodyRectangle() const;

        /*
        description: Get the head rectangle.
        return: rectangle_t
        precondition: head rectangle exists.
        postcondition: the head rectangle is returned.
        */
        rectangle_t getHeadRectangle() const;

        /*
        description: Get the step
        return: int
        precondition: player exists
        postcondition: step is returned.
        */
        int getStep() const;

        /*
        description: Get normal color
        return: color
        precondition: player exists
        postcondition: normal color is returned
        */
        color getNormalColor() const;

        /*
        description: Get cleared color
        return: color
        precondition: player exists
        postcondition: cleared color is returned
        */
        color getClearedColor() const;

        /*
        description: Get hp
        return: int
        precondition: player exists
        postcondition: hp is returned
        */
        int getHP() const;

        /*
        description: Get hitBox
        return: circle_t
        precondition: player exists
        postcondition: hitBox is returned
        */
        circle_t getHitBox() const;

        /*
        description: decrement the player's hp
        return: none
        precondition: player exists, hp not zero.
        postcondition: hp decreased by 1.
        */
        void hurt();

        // ---Display helpers---

        /*
        description: Draw the player based on normal color.
        return: none
        precondition: SDL_Plotter exists
        postcondition: player is drawn.
        */
        void draw(SDL_Plotter& g) const;

        /*
        description: clear the player based on cleared color.
        return: none
        precondition: SDL_Plotter exists
        postcondition: player is undrawn.
        */
        void undraw(SDL_Plotter& g) const;

        // Actions

        /*
        description: Move player by num of steps. Steps is controlled by the
                     step size. So if step size is 10, then a +1 step means
                     one step to right, -1 means one step to left.
        return: none
        precondition: input is valid, player exists.
        postcondition: player position is updated.
        */
        void movePlayerByNSteps(const int);

        /*
        description: Fire a bullet and add bullet to vector
        return: none
        precondition: vector exist for bullet
        postcondition: bullet is added to vector.
        */
        // TODO maybe change this to return a bullet object?
        // bomb? power up? shield? HP?
        void fire(vector<bullet_t>&);

};

#endif // PLAYER_H_INCLUDED
