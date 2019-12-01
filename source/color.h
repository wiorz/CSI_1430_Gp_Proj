#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct color
{
    int R, G, B;

    color()
    {
        R= G= B= 0;
    }

    color(int r, int g, int b)
    {
        R = r;
        G = g;
        B = b;
    }

    color(const color& c)
    {
        R = c.R;
        G = c.G;
        B = c.B;
    }
};

const color REDCOLOR(220, 0, 0);
const color BLACKCOLOR(0, 0, 0);
const color WHITECOLOR(255, 255, 255);
const color GREENCOLOR(5, 250, 10);

#endif // COLOR_H_INCLUDED
