#ifndef ALIEN_GROUP_H_INCLUDED
#define ALIEN_GROUP_H_INCLUDED

#include <vector>
#include <ostream>
#include "circle.h"
#include "alien.h"
#include "SDL_Plotter.h"
#include "color.h"

using namespace std;

const int DEFAULTROWSIZE = 5;
const int DEFAULTCOLSIZE = 11;
/*
const int a[32][28] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
*/
class alien_group
{
    private:
        // 1 = right, -1 = left;
        int direction;

    public:
        /*
        description: constructor
        return: alien_group
        precondition: SDL_Plotter exists, has a speed for step size
        postcondition: constructed the alien_group
        */
        alien_group(SDL_Plotter&, const int);

        /*
        description: a vector of alien_t, meant to be private but allocated
                    as public.
        return: vector<alien_t>
        precondition:
        postcondition: constructed the alien_group
        */
        vector<alien_t> aliens;

        /*
        description: set the direction from an int, expect to be 1 or -1.
        return: none
        precondition: int is a valid.
        postcondition: set direction to that int.
        */
        void setDirection(const int);

        /*
        description: A reference to the vector<alien_t> aliens
        return: ref to vector<alien_t>
        precondition: alien_group is constructed.
        postcondition: return the reference to the aliens data member.
        */
        vector<alien_t>& getAlienGroupVect();

        /*
        description: return the size of the vector<alien_t> as unsigned int.
        return: unsigned int
        precondition: alien_group is constructed.
        postcondition: nothing is changed.
        */
        unsigned int getAlienGroupSize() const;

        /*
        description: get the alien_t at index
        return: alien_t
        precondition: aliens exists, and the index is valid.
        postcondition: constructed the alien_group
        */
        alien_t getAlienAtIndex(const int);

        void moveAliensByNSteps(SDL_Plotter&, const int);

        void removeAlienAtIndex(SDL_Plotter&, const int);

        void fireAtIndex(vector<bullet_t>&, const int);

        void draw(SDL_Plotter&);

        void undraw(SDL_Plotter&);

};

#endif // ALIEN_GROUP_H_INCLUDED
