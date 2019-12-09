// Worked on this on 11/13 Wednesday, and 11/15 Friday
// test commit

#include <iostream>
#include <ctime>
#include "SDL_Plotter.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "circle.h"
#include "player.h"
#include "alien.h"
#include <fstream>

using namespace std;

const int WINDOWSWIDTH = 1080;
const int WINDOWSHEIGHT = 720;
const int SPEED = 15;

int menu();
int credits();
int ScoreBoard();

int main(int argc, char* argv[])
{
	int option;
	do {
		SDL_Plotter g(WINDOWSHEIGHT, WINDOWSWIDTH);
		srand(time(0));
		char key;
		player p(g, SPEED);
		alien_t a1(point(g.getCol()/2, g.getRow()/2), SPEED);
		alien_t a2(point(g.getCol()/2, g.getRow()/2), SPEED);
		option = menu();
		while (option == 2 || option == 3) {
			if (option == 2)
				option = credits();
			else if (option == 3)
				option = ScoreBoard();
			else if (option != 2 && option != 3)
				break;
		}

		while(!g.getQuit() && option == 1)
		{
			if(g.kbhit())
			{

				cout << alien_t::totalCount << endl;
				a1.setNormalColor(BLACKCOLOR);
				a1.draw(g);
				a2.setNormalColor(BLACKCOLOR);
				a2.draw(g);

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
							a1.moveByNStepsInXCoord(1);
						}

						break;
					case LEFT_ARROW:
						if(p.getBodyRectangle().getUpperLeft().x > 0)
						{
							p.movePlayerByNSteps(-1);
							a1.moveByNStepsInXCoord(-1);
						}
						break;
					case UP_ARROW:
						a1.moveByNStepsInYCoord(-1);
						break;
					case DOWN_ARROW:
						a1.moveByNStepsInYCoord(1);
						break;
					case '3':
						a2.moveByNStepsInYCoord(1);
						break;
					case '1':
						if(p.getBodyRectangle().getLowerRight().x
						   < WINDOWSWIDTH) {
						a2.moveByNStepsInXCoord(-1);
						}
						break;
					case '2':
						a2.moveByNStepsInYCoord(-1);
						break;
					case '4':
						if(p.getBodyRectangle().getUpperLeft().x > 0) {
						a2.moveByNStepsInXCoord(1);
						}
						break;
					case ' ':
						break;
				}

				// Steps 3.
				// Draw the updated rectangle
				// Important to reset color to what we want here.
				p.draw(g);
				a1.setNormalColor(GREENCOLOR);
				a2.setNormalColor(GREENCOLOR);
				a1.draw(g);
				a2.draw(g);
			}


			g.update();
		}

		// Clean up
		SDL_Quit();
	} while (option != 4);
	return 0;
}

int menu() {
	int entry;
	cout << "Space Invaders Ripoff \n\n"
		 << "1. Start\n\n"
		 << "2. Credits\n\n"
		 << "3. ScoreBoard\n\n"
		 << "4. quit game\n\n";
		cin >> entry;
		return entry;
}

int credits() {
	int entry;
	cout << "CREDITS:\n\n"
		 << "Ivan Ko: created the player, the enemies and the bullets\n\n"
		 << "Yi Ding: did Collision, scoring system, menu\n\n"
		 << "Third person: dunno\n\n"
		 << "select the menu option you desire\n\n";
	cin >> entry;
	return entry;
}
int ScoreBoard() {
	ifstream in;
	string name;
	int entry;
	in.open("SCOREBOARD");
	cout << endl;
	while(getline(in, name)) {
		cout << name << endl;
	}
	in.close();
	cout << endl << "select the menu option you desire\n\n";
	cin >> entry;
	cout << endl;
	return entry;
}
