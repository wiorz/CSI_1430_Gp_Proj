#include "test.h"


bullet::bullet() {
	count++;
	rect.getHeadRectangle();
	p = rect.getUpperLeft();
	p1 = rect.getLowerRight();
	b[count].x = (double)(p.x + p1.x) / 2;
	b[count].y = p.y + 1;
}

void bullet::drawBullet(SDL_Plotter& g) {
	int min = b[count].y;
	for (int i = 0; i < count.size(); i++) {
		if (min > b[count].y)
			min = b[count].y;
	}
	min = 718 - min;
	for (int j = 0; j < min; j++) {
		if (b.size() == 0)
			break;
		for (int i = 0; i < count; i++) {
			g.plotPixel(b[count].x, b[count].y, 5, 250, 10);
			if (b[count].y == 718)
				b.erase(b.begin() + i);
			else
				b[count].y++;
		}
	}
}

void clearBullet(SDL_Plotter& g) {
}
