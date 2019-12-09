#ifndef ALIEN_GROUP_H_INCLUDED
#define ALIEN_GROUP_H_INCLUDED

#include <vector>
#include <ostream>
#include "circle.h"
#include "alien.h"
#include "SDL_Plotter.h"

using namespace std;

const int DEFAULTROWSIZE = 5;
const int DEFAULTCOLSIZE = 11;

class alien_group
{
    private:
        vector<alien_t> aliens;
        // 1 = right, -1 = left;
        int direction;

    public:
        alien_group(SDL_Plotter&, const int);

        void setDirection(const int);

        void moveAliensByNSteps(SDL_Plotter&, const int);

        void removeAlienAtIndex(SDL_Plotter&, const int);

        void fireAtIndex(const int);

        void draw(SDL_Plotter&);

        void undraw(SDL_Plotter&);

};

#endif // ALIEN_GROUP_H_INCLUDED
