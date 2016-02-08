#include "./tools.h"
#include "./game.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int rand_comp(rps &game)
{
	int t = (rand() % 3)+1;
	cout << "rand t = " << t << endl;
	return t;
}

int choose_comp(rps &game, char prev)
{
	int t = (game.getturns() % 3); 
	int r = (rand() % 3);
	if (r == t)
	{
		cout << "r = t" << endl;
		return 0;
	}
	else {cout << "r != t" << endl;}
	return 1;
}

char play_rock(rps &game, int res, char prev)
{
	rock human;
	int cres = choose_comp(game, prev);
	int bres;
	rock rcomp;
	paper pcomp;
	scissors scomp;
	if (cres == 1)
	{
		cout << "prev = " << prev << endl;
		if (prev == 'r'){res = human.fight(rcomp);}
		if (prev == 'p'){res = human.fight(pcomp);}
		if (prev == 's'){res = human.fight(scomp);}
	}
	if (cres == 0)
	{
		bres = rand_comp(game);
		if (bres == 1){res = human.fight(rcomp);}
		if (bres == 2){res = human.fight(pcomp);}
		if (bres == 3){res = human.fight(scomp);}
	}
	if (res == 1)
	{
		cout << endl << "YOU HAVE WON!!! CONGRATULATIONS!!!" << endl << endl;
		game.inchw();
	}
	if (res == 0)
	{
		cout << endl << "DEFEAT!! YOU BRING SHAME TO YOUR ANCESTORS!!!" << endl << endl;
		game.inccw();
	}
	if (res == -1)
	{
		cout <<  endl << "A TIE?!?! YOU FOOLS!! NOBODY WINS!!" << endl << endl;
		game.inct();
	}
	if (cres == 1)
	{
		if (prev == 'r'){return rcomp.gettype();}
		if (prev == 'p'){return pcomp.gettype();}
		if (prev == 's'){return scomp.gettype();}
	}
	if (cres == 0)
	{
		return prev;
	}
}

char play_paper(rps &game, int res, char prev)
{
	paper human;
	int cres = choose_comp(game, prev);
	rock rcomp;
	paper pcomp;
	scissors scomp;
	if (cres == 1)
	{
		if (prev == 'r'){res = human.fight(rcomp);}
		if (prev == 'p'){res = human.fight(pcomp);}
		if (prev == 's'){res = human.fight(scomp);}
	}
	if (cres == 0)
	{
		res = rand_comp(game) - 1;
	}
	if (res == 1)
	{
		cout << "YOU HAVE WON!!! CONGRATULATIONS!!!" << endl;
		game.inchw();
	}
	if (res == 0)
	{
		cout << "DEFEAT!! YOU BRING SHAME TO YOUR ANCESTORS!!!" << endl;
		game.inccw();
	}
	if (res == -1)
	{
		cout << "A TIE?!?! YOU FOOLS!! NOBODY WINS!!" << endl;
		game.inct();
	}
	if (cres == 1)
	{
		if (prev == 'r'){return rcomp.gettype();}
		if (prev == 'p'){return pcomp.gettype();}
		if (prev == 's'){return scomp.gettype();}
	}
	if (cres == 0)
	{
		return prev;
	}
}

char play_scissors(rps &game, int res, char prev)
{
	scissors human;
	int cres = choose_comp(game, prev);
	rock rcomp;
	paper pcomp;
	scissors scomp;
	if (cres == 1)
	{
		if (prev == 'r'){res = human.fight(rcomp);}
		if (prev == 'p'){res = human.fight(pcomp);}
		if (prev == 's'){res = human.fight(scomp);}
	}
	if (cres == 0)
	{
		res = rand_comp(game) - 1;
	}
	if (res == 1)
	{
		cout << "YOU HAVE WON!!! CONGRATULATIONS!!!" << endl;
		game.inchw();
	}
	if (res == 0)
	{
		cout << "DEFEAT!! YOU BRING SHAME TO YOUR ANCESTORS!!!" << endl;
		game.inccw();
	}
	if (res == -1)
	{
		cout << "A TIE?!?! YOU FOOLS!! NOBODY WINS!!" << endl;
		game.inct();
	}
	if (cres == 1)
	{
		if (prev == 'r'){return rcomp.gettype();}
		if (prev == 'p'){return pcomp.gettype();}
		if (prev == 's'){return scomp.gettype();}
	}
	if (cres == 0)
	{
		return prev;
	}
}

void show_scores(rps &game)
{
	cout << "SO FAR:" << endl << endl;
	cout << "YOU HAVE WON " << game.gethwins() << " TIMES!" << endl;
	cout << "THE COMPUTER HAS WON " << game.getcwins() << " TIMES!" << endl;
	cout << "YOU HAVE TIED " << game.getties() << " TIMES!" << endl;
	cout << "PREPARE YOURSELF, WARRIOR!!!" << endl;	
}