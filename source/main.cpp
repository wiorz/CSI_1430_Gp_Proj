// Worked on this on 11/13 Wednesday, and 11/15 Friday
// test commit

#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "SDL_Plotter.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "circle.h"
#include "player.h"
#include "alien.h"
#include "alien_group.h"
#include "bullet.h"
#include "collision.h"

using namespace std;

const int WINDOWSWIDTH = 1080;
const int WINDOWSHEIGHT = 720;
const int SPEED = 15;

int menu();
int credits();
int ScoreBoard();
void setScore(int);

int main(int argc, char* argv[])
{
	int option;
	do {
		option = 0;
		SDL_Plotter g(WINDOWSHEIGHT, WINDOWSWIDTH);
		srand(time(0));
		char key;
		bool quit = false;
		player p(g, SPEED);
		alien_group aG(g, SPEED);
        vector<bullet_t> playerBTVect, alienBTVect;
        int tmpTimeSec;
		option = menu();
		clock_t startTime = clock();
		while (option == 2 || option == 3) {
			if (option == 2)
				option = credits();
			else if (option == 3)
				option = ScoreBoard();
			else if ((option != 2 && option != 3) || isdigit(option) == false)
				break;
		}

		while(!g.getQuit() && option == 1 && quit == false)
        {
		    g.initSound("clear.wav");
		    g.initSound("bleeeat.wav");

            clock_t currTime = clock();

            // Move player bullet
            if(playerBTVect.size())
            {
                playerBTVect.at(0).undraw(g);
            }

            if(alienBTVect.size())
            {
                for(unsigned int i = 0; i < alienBTVect.size(); i++)
                {
                    alienBTVect.at(i).undraw(g);
                }

            }

            // Handle Bullet boundary and collision.
            if(playerBTVect.size())
            {
                if(playerBTVect.at(0).getCenterTopPos().y <= 0)
                {
                    playerBTVect.at(0).
                    killAndRemoveFromBTVector(playerBTVect, 0);
                } else
                {
                    playerBTVect.at(0).moveByNStepsInYCoord(-1);
                }
            }

            if(alienBTVect.size())
            {
                for(unsigned int i = 0; i < alienBTVect.size(); i++)
                {
                    if(alienBTVect.at(i).getCenterTopPos().y >= 720)
                    {
                        alienBTVect.at(i).
                        killAndRemoveFromBTVector(alienBTVect, i);
                    } else
                    {
                        alienBTVect.at(i).moveByNStepsInYCoord(1);
                    }
                }
            }
            tmpTimeSec = static_cast<int>(currTime - startTime)/
                                                    CLOCKS_PER_SEC;
            //cout << "seconds: " << tmpTimeSec << endl;
            if(static_cast<int>(currTime - startTime) % 60 == 1)
            {
                aG.undraw(g);
                if(rand() % 10 == 1 || rand() % 10 == 2)
                {
                    aG.fireAtIndex(alienBTVect,
                                   rand() % aG.getAlienGroupSize());
                }
                aG.moveAliensByNSteps(g, 1);
                aG.draw(g);
            }
			if (p.getHP() == 1) {
				p.setNormalColor(REDCOLOR);
			}
			if (p.getHP() == 0 || aG.getAlienGroupSize() == 0 ) {
				quit = true;
				cout << "you lost\n Your Score: ";
			}
				if(g.kbhit())
                {


                    //cout << alien_t::totalCount << endl;

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
                            p.fire(playerBTVect);
                            break;
                        case DOWN_ARROW:
                            break;
                        case ' ':
							bool pause = true;
							while (pause) {
								g.Sleep(100);
								if (g.kbhit())
									pause = false;
							}
                            break;
                    }

                    // Steps 3.
                    // Draw the updated rectangle
                    // Important to reset color to what we want here.
                    p.draw(g);
                }

            collid2KillPlayer(p, alienBTVect, g);
            collid2KillAlien(aG, playerBTVect, g);

            if(playerBTVect.size())
            {
                playerBTVect.at(0).draw(g);
            }

            if(alienBTVect.size())
            {
                for(unsigned int i = 0; i < alienBTVect.size(); i++)
                {
                    alienBTVect.at(i).draw(g);
                }

            }


			g.update();
		}
		// Clean up
		SDL_Quit();
		if (option != 4) {
			cout << (55 - alien_t::totalCount) * 1000 << endl;
			setScore(55 - alien_t::totalCount);
		}
	} while (option != 4);
	return 0;
}

int menu() {
	int entry;
	string name;
	cout << "Space Invaders Ripoff \n\n"
		 << "1. Start\n\n"
		 << "2. Credits\n\n"
		 << "3. ScoreBoard\n\n"
		 << "4. quit game\n\n";
		cin >> name;
		do {
			if (name == "1") {
				entry = 1;
				break;
			}
			else if (name == "2") {
				entry = 2;
				break;
			}
			else if (name == "3") {
				entry = 3;
				break;
			}
			else if (name == "4") {
				entry = 4;
				break;
			}
			cout << "Only integers allowed\n";
			cin >> name;
			cout << endl;
		} while (name != "1" || name != "2" || name != "3" || name != "4");
		return entry;
}

int credits() {
	int entry;
	string name;
	cout << "CREDITS:\n\n"
		 << "Ivan Ko: created the player, the enemies and the bullets and"
		 << "did 2nd Collision and HP\n\n"
		 << "Yi Ding: did 1st Collision, scoring system, menu and player HP\n\n"
		 << "Third person: never showed up, did nothing\n\n"
		 << "select the menu option you desire\n\n";
	cin >> name;
	do {
		if (name == "1") {
			entry = 1;
			break;
		}
		else if (name == "2") {
			entry = 2;
			break;
		}
		else if (name == "3") {
			entry = 3;
			break;
		}
		else if (name == "4") {
			entry = 4;
			break;
		}
		cout << "Only integers allowed\n";
		cin >> name;
		cout << endl;
	} while (name != "1" || name != "2" || name != "3" || name != "4");
	return entry;
}
int ScoreBoard() {
	ifstream in;
	string name;
	int entry;
	vector<string> names;
	vector<int> scores;
	in.open("SCOREBOARD");
	cout << endl;
	while(getline(in, name)) {
	istringstream iss (name);
	iss >> name >> entry;
	scores.push_back(entry);
	names.push_back(name);
	}
	in.close();
	for (int i = 0; i < scores.size() - 1; i++) {
		for (int j = 0; j < scores.size() - i - 1; j++) {
			if (scores[j] < scores[j + 1])
				swap(scores[j], scores[j + 1]);
			if (names[j] < names[j + 1])
				swap(names[j], names[j + 1]);
		}
	}
	for (int i = 0; i < scores.size(); i++)
		cout << names[i] << " " << scores[i] << endl;
	cout << endl << "select the menu option you desire\n\n";
	cin >> name;
	do {
		if (name == "1") {
			entry = 1;
			break;
		}
		else if (name == "2") {
			entry = 2;
			break;
		}
		else if (name == "3") {
			entry = 3;
			break;
		}
		else if (name == "4") {
			entry = 4;
			break;
		}
		cout << "Only integers allowed\n";
		cin >> name;
		cout << endl;
	} while (name != "1" || name != "2" || name != "3" || name != "4");
	return entry;
}
void setScore(int n) {
	ofstream out;
	string str;
	out.open("SCOREBOARD", std::ios_base::app);
	cout << "INPUT YOUR NAME (~10 characters)\n\n";
	cin >> str;
	cout << endl;
	out << str << '\t' << 1000 * n << endl;
	out.close();
}
