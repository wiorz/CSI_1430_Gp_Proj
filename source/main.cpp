// Worked on this on 11/13 Wednesday, and 11/15 Friday

#include <iostream>
#include <ctime>
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "circle.h"
#include "SDL_Plotter.h"

using namespace std;

const int CANNONROW = 5;
const int CANNONCOL = 5;

int main(int argc, char* argv[])
{
    SDL_Plotter g(720, 1080);
    srand(time(0));
    char key;

    int speed = 3;
    int cannonX = g.getCol() / 2;
    int cannonY = g.getRow() / 2;

    rectangle_t rec(point(10, 10), point(cannonX,cannonY), RED);

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
            rec.setColor(WHITECOLOR);
            rec.draw(g);

            // Step 2.
            // Update coordinates
            point tmpLR = rec.getLowerRight();
            point tmpUL = rec.getUpperLeft();

            switch(toupper(key))
            {

                case RIGHT_ARROW:
                        tmpLR.x += speed;
                        tmpUL.x += speed;
                        rec.setLowerRight(tmpLR);
                        rec.setUpperLeft(tmpUL);
                        break;
                case LEFT_ARROW:
                        tmpLR.x -= speed;
                        tmpUL.x -= speed;
                        rec.setLowerRight(tmpLR);
                        rec.setUpperLeft(tmpUL);
                        break;
                case UP_ARROW:
                        speed++;
                        break;
                case DOWN_ARROW:
                        // Avoid negative speed!
                        if(speed > 1)
                        {
                            speed--;
                            break;
                        }

            }

            // Steps 3.
            // Draw the updated rectangle
            // Important to reset color to what we want here.
            rec.setColor(RED);
            rec.draw(g);

        }

        g.update();
    }

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
