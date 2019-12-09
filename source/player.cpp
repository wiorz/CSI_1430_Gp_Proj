#include "player.h"
#include <ostream>

using namespace std;

player::player()
{
    body.setLowerRight(point(WIDTH/2 + UNITSIZE * 1.5,
                             HEIGHT - UNITSIZE * 0.5));
    body.setUpperLeft(point(WIDTH/2 - UNITSIZE * 1.5,
                            HEIGHT - UNITSIZE * 1.5));
    head.setLowerRight(point(WIDTH/2 + UNITSIZE * 0.5,
                             HEIGHT - UNITSIZE *1.5));
    head.setUpperLeft(point(WIDTH/2 - UNITSIZE * 0.5,
                            HEIGHT - UNITSIZE * 2.0));
    step = DEFAULTSTEP;
    normal = GREENCOLOR;
    cleared = BLACKCOLOR;
    hp = DEFAULTHP;
    hitBox.setCenter(point(WIDTH/2, HEIGHT - UNITSIZE));
    hitBox.setRadius(UNITSIZE / 2);
}

player::player(SDL_Plotter& g, int stepSize)
{
    body.setLowerRight(point(g.getCol()/2 + UNITSIZE * 1.5,
                             g.getRow() - UNITSIZE * 0.5));
    body.setUpperLeft(point(g.getCol()/2 - UNITSIZE * 1.5,
                            g.getRow() - UNITSIZE * 1.5));
    head.setLowerRight(point(g.getCol()/2 + UNITSIZE * 0.5,
                             g.getRow() - UNITSIZE *1.5));
    head.setUpperLeft(point(g.getCol()/2 - UNITSIZE * 0.5,
                            g.getRow() - UNITSIZE * 2.0));

    step = stepSize;
    normal = GREENCOLOR;
    cleared = BLACKCOLOR;
    hp = DEFAULTHP;

    hitBox.setCenter(point((body.getUpperLeft().x + UNITSIZE / 2 + 20),
                           head.getLowerRight().y));
    hitBox.setRadius(UNITSIZE );
}

player::player(const rectangle_t& rec)
{
    body = rec;
    // Make head relative to the mid point of body.
    point bodyLR = body.getLowerRight();
    point bodyUL = body.getUpperLeft();
    int headMidX = (bodyLR.x + bodyUL.x) / 2;
    int headLowerY = bodyUL.y;
    head.setLowerRight(point(headMidX + UNITSIZE * 0.5, headLowerY));
    head.setUpperLeft(point(headMidX - UNITSIZE * 0.5,
                            headLowerY + UNITSIZE * 0.5));
    step = DEFAULTSTEP;
    normal = rec.getColor();
    cleared = BLACKCOLOR;
    hp = DEFAULTHP;
}

player::player(const rectangle_t& rec, int stepVal)
{
    body = rec;
    // Make head relative to the mid point of body.
    point bodyLR = body.getLowerRight();
    point bodyUL = body.getUpperLeft();
    int headMidX = (bodyLR.x + bodyUL.x) / 2;
    int headLowerY = bodyUL.y;
    head.setLowerRight(point(headMidX + UNITSIZE * 0.5, headLowerY));
    head.setUpperLeft(point(headMidX - UNITSIZE * 0.5,
                            headLowerY + UNITSIZE * 0.5));
    step = stepVal;
    normal = rec.getColor();
    cleared = BLACKCOLOR;
    hp = DEFAULTHP;
}

player::player(const rectangle_t& rec, int stepVal, color bodyColor,
               color clearedColor)
{
    body = rec;
    // Make head relative to the mid point of body.
    point bodyLR = body.getLowerRight();
    point bodyUL = body.getUpperLeft();
    int headMidX = (bodyLR.x + bodyUL.x) / 2;
    int headLowerY = bodyUL.y;
    head.setLowerRight(point(headMidX + UNITSIZE * 0.5, headLowerY));
    head.setUpperLeft(point(headMidX - UNITSIZE * 0.5,
                            headLowerY + UNITSIZE * 0.5));
    step = stepVal;
    normal = bodyColor;
    cleared = clearedColor;
    hp = DEFAULTHP;
}

// Mutators
void player::setBodyRectangle(const rectangle_t& rec)
{
    body = rec;
    // Make head relative to the mid point of body.
    point bodyLR = body.getLowerRight();
    point bodyUL = body.getUpperLeft();
    int headMidX = (bodyLR.x + bodyUL.x) / 2;
    int headLowerY = bodyUL.y;
    head.setLowerRight(point(headMidX + UNITSIZE * 0.5, headLowerY));
    head.setUpperLeft(point(headMidX - UNITSIZE * 0.5,
                            headLowerY + UNITSIZE * 0.5));
}

void player::setStep(const int stepVal)
{
    step = stepVal;
}

void player::setNormalColor(const color nColor)
{
    normal = nColor;
}

void player::setClearedColor(const color cColor)
{
    cleared = cColor;
}


// Getters
rectangle_t player::getBodyRectangle() const
{
    return body;
}

rectangle_t player::getHeadRectangle() const
{
    return head;
}

int player::getStep() const
{
    return step;
}

color player::getNormalColor() const
{
    return normal;
}

color player::getClearedColor() const
{
    return cleared;
}

int player::getHP() const
{
    return hp;
}

circle_t player::getHitBox() const
{
    return hitBox;
}

void player::hurt()
{
    if(!(hp <= 0))
    {
        hp--;
    }
}


// Display helpers
void player::draw(SDL_Plotter& g) const
{
    // Draw body
    for(int y = min(body.getUpperLeft().y, body.getLowerRight().y);
        y < max(body.getUpperLeft().y, body.getLowerRight().y); y++)
    {
        for(int x = min(body.getUpperLeft().x, body.getLowerRight().x);
            x < max(body.getUpperLeft().x, body.getLowerRight().x); x++)
        {
            if(x >= 0 && y >= 0 && x < g.getCol() && y < g.getRow())
                {
                    g.plotPixel(x, y, normal.R, normal.G, normal.B);
                }

        }
    }

    // Draw head
    for(int y = min(head.getUpperLeft().y, head.getLowerRight().y);
        y < max(head.getUpperLeft().y, head.getLowerRight().y); y++)
    {
        for(int x = min(head.getUpperLeft().x, head.getLowerRight().x);
            x < max(head.getUpperLeft().x, head.getLowerRight().x); x++)
        {
            if(x >= 0 && y >= 0 && x < g.getCol() && y < g.getRow())
                {
                    g.plotPixel(x, y, normal.R, normal.G, normal.B);
                }
        }
    }
}

void player::undraw(SDL_Plotter& g) const
{
    // Draw body
    for(int y = min(body.getUpperLeft().y, body.getLowerRight().y);
        y < max(body.getUpperLeft().y, body.getLowerRight().y); y++)
    {
        for(int x = min(body.getUpperLeft().x, body.getLowerRight().x);
            x < max(body.getUpperLeft().x, body.getLowerRight().x); x++)
        {
            if(x >= 0 && y >= 0 && x < g.getCol() && y < g.getRow())
                {
                    g.plotPixel(x, y, cleared.R, cleared.G, cleared.B);
                }

        }
    }

    // Draw head
    for(int y = min(head.getUpperLeft().y, head.getLowerRight().y);
        y < max(head.getUpperLeft().y, head.getLowerRight().y); y++)
    {
        for(int x = min(head.getUpperLeft().x, head.getLowerRight().x);
            x < max(head.getUpperLeft().x, head.getLowerRight().x); x++)
        {
            if(x >= 0 && y >= 0 && x < g.getCol() && y < g.getRow())
                {
                    g.plotPixel(x, y, cleared.R, cleared.G, cleared.B);
                }
        }
    }

}


// Actions
void player::movePlayerByNSteps(const int val)
{
    point prevBodyLR = body.getLowerRight();
    body.setLowerRight(point(prevBodyLR.x + val * step, prevBodyLR.y));
    point prevBodyUL = body.getUpperLeft();
    body.setUpperLeft(point(prevBodyUL.x + val * step, prevBodyUL.y));

    point prevHeadLR = head.getLowerRight();
    head.setLowerRight(point(prevHeadLR.x + val * step, prevHeadLR.y));
    point prevHeadUL = head.getUpperLeft();
    head.setUpperLeft(point(prevHeadUL.x + val * step, prevHeadUL.y));

    hitBox.setCenter(point((body.getUpperLeft().x + UNITSIZE / 2 + 20),
                           head.getLowerRight().y));

    return;
}

void player::fire(vector<bullet_t>& btVec)
{
    if(!btVec.size())
    {
        int xpos = (head.getUpperLeft().x + head.getLowerRight().x)/ 2;
        btVec.push_back(bullet_t(point(xpos, head.getUpperLeft().y - UNITSIZE),
                                 UNITSIZE / 3, 2));
    }

}

