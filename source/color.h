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

const color RED(220, 0, 0);
const color BLACK(0, 0, 0);
const color WHITECOLOR(255, 255, 255);

#endif // COLOR_H_INCLUDED
