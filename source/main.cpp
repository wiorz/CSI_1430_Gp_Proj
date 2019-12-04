// Worked on this on 11/13 Wednesday, and 11/15 Friday
// test commit

#include <iostream>
#include <ctime>
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "circle.h"
#include "player.h"
#include "SDL_Plotter.h"

using namespace std;

const int WINDOWSWIDTH = 1080;
const int WINDOWSHEIGHT = 720;
<<<<<<< HEAD
//const int SPEED = 5;
=======
const int SPEED = 10;
>>>>>>> master

int main(int argc, char* argv[])
{
    SDL_Plotter g(WINDOWSHEIGHT, WINDOWSWIDTH);
    srand(time(0));
    char key;
    player p(g, SPEED);

    while(!g.getQuit())
    {
        if(g.kbhit())
        {
            key = g.getKey();

            // Steps to update:
            // 1. Delete the last object by resetting them to background color
            // 2. Update coordinates of objects
            // 3. Draw updated object.

            // Step 1.
            // "Erase" previous rectangle by setting it to background color
            // Shows nothing with any key input.
            p.undraw(g);




            // Step 2.
            // Update coordinates

            switch(toupper(key))
            {

                case RIGHT_ARROW:
                    if(p.getBodyRectangle().getLowerRight().x
                       < WINDOWSWIDTH)
                    {
                        p.movePlayerByNSteps(1);
                    }

                    break;
                case LEFT_ARROW:
                    if(p.getBodyRectangle().getUpperLeft().x > 0)
                    {

                        p.movePlayerByNSteps(-1);
                    }
                    break;
                case UP_ARROW:
                    //speed++;
                    break;
                case DOWN_ARROW:
                    break;

            }

            // Steps 3.
            // Draw the updated rectangle
            // Important to reset color to what we want here.
            p.draw(g);

        }


        g.update();
    }

    // Clean up
    SDL_Quit();
    return 0;
}

/*
Old code to draw random lines:
SDL_Plotter g(500, 500);
    srand(time(0));
    int count = 0;
    point p;
    p.x = 99;
    p.y = 11;

    point p2;
    p.x = 250;
    p.y = 250;

    line myLine(p, p2);
    p.display(cout);
    p2.display(cout);
    myLine.display(cout);

    p.display(cout);

    while(!g.getQuit())
    {
        if(g.kbhit())
        {
            char Key = g.getKey();
        }
        p.x += -1 + rand()%3;
        p.y += -1 + rand()%3;
        if(count >= 1025)
        {
            cout << p.c.R << " " << p.c.G << " " << p.c.B << endl;
            if(p.c.R < 255)
            {
                p.c.R += 1;
            } else if (p.c.G < 255)
            {
                p.c.G += 1;
            } else if(p.c.B < 255)
            {
                p.c.B += 1;
            } else
            {
                p.c.R = 0;
                p.c.G = 0;
                p.c.B = 0;

            }
            myLine.setPointTwo(point(rand() % 500, rand() % 500));
            count = 0;
        }
        p.draw(g);
        p2.draw(g);
        myLine.setPointOne(point(rand() % 500, rand() % 500));
        myLine.setColor(color(rand() % 256, rand() % 256, rand() % 256));
        myLine.draw(g);
        count++;
        g.update();

*/

/*
// To draw random circles:
int main(int argc, char* argv[])
{
    SDL_Plotter g(1000, 1000);
    g.initSound("Honk.wav"); //to get sound
    srand(time(0));
    int count = 0;
    // rectangle_t box[100]; The commented out part is for drawing rectangles.
    circle_t ball[99];
         for(int i = 0; i < 99; i++)
    {
        ball[i].setCenter(point(rand() % g.getCol(), rand() % g.getRow()));
        ball[i].setRadius(rand() % 100);
        ball[i].setColor(color(rand()% 256, rand()% 256, rand()% 256));
    }

    while(!g.getQuit())
    {
        if(g.kbhit())
        {
            char Key = g.getKey();
            switch(Key)
            { case 'P':
                g.playSound("Honk.wav");
                break;
            }
        }

        for(int i = 0; i < 99; i++)
        {
            ball[i].draw(g);
            // g.update(); // Flush out the buffer each time.
        }

        g.update();
        for(int i = 0; i < 99; i++)
        {
            ball[i].setCenter(point(rand() % g.getCol(), rand() % g.getRow()));
            ball[i].setRadius(rand() % 100);
            ball[i].setColor(color(rand()% 256, rand()% 256, rand()% 256));
        }

    }
}
*/
