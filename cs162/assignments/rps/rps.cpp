#include "./tools.h"
#include "./game.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//sets and outputs scores for the game
void setscores(rps &game, int res)
{
	if (res == 0)
	{
		game.inccw();
	}
	if (res == 1)
	{
		game.inchw();
	}
	if (res == 2)
	{
		game.inct();
	}
	cout << "Computer wins:\t\t" << game.getcwins() << endl;
	cout << "Human wins:\t\t" << game.gethwins() << endl;
	cout << "Ties:\t\t\t" << game.getties() << endl;
}

//plays the fights between different tools
void play_fights(rps &game, char comp_choice)
{
	cout << "Type selected: " << game.gethuman()->gettype() << endl;
	rock rcomp;
	paper pcomp;
	scissors scomp;
	int res;
	if (game.gethuman()->gettype() == 'r')
	{
		rock human;
		if (comp_choice == 'r'){res = human.fight(rcomp, human);}
		if (comp_choice == 'p'){res = human.fight(pcomp, human);}
		if (comp_choice == 's'){res = human.fight(scomp, human);}
	}
	if (game.gethuman()->gettype() == 'p')
	{
		paper human;
		if (comp_choice == 'r'){res = human.fight(rcomp, human);}
		if (comp_choice == 'p'){res = human.fight(pcomp, human);}
		if (comp_choice == 's'){res = human.fight(scomp, human);}
	}
	if (game.gethuman()->gettype() == 's')
	{
		scissors human;
		if (comp_choice == 'r'){res = human.fight(rcomp, human);}
		if (comp_choice == 'p'){res = human.fight(pcomp, human);}
		if (comp_choice == 's'){res = human.fight(scomp, human);}
	}
	setscores(game, res);
}

//chooses the next move for computer
char choice(rps &game, char prev)
{
	int t = game.getturns() % 3;
	int r = rand() % 3;
	int q = (rand() * t) % 3;
	if (t == r)
	{
		if (prev == 'r'){return 'r';}
		if (prev == 'p'){return 'p';}
		if (prev == 's'){return 's';}
		else {cout << "error" << endl;}
	}
	if (t != r)
	{
		
		if (t == 0){return 'r';}
		if (t == 1){return 'p';}
		if (t == 2){return 's';}
	}
}

//plays the round
char play_round(rps &game, char prev)
{
	game.incturns();
	cout << "Turn " << game.getturns() << endl;
	cout << "Select your tool.\t\t";
	char sel;
	cin >> sel;
	game.sethuman(sel);
	
	char comp_choice = choice(game, prev);
	play_fights(game, comp_choice);
	return comp_choice;
}

//play the game
void play_game()
{
	rps game;
	char prev = 'p';
	cout << endl << "Welcome to rock, paper, scissors." << endl << endl;
	cout << "Please select your tool with r, p or s, and exit with e." << endl;
	for (int i = 0; i < 50; i++)
	{
		prev = play_round(game, prev);
	}
}