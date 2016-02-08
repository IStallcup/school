#include "./tools.h"
#include "./game.h"
#include <iostream>

using namespace std;

int main()
{
	rps game;
	cout << endl << "WELCOME!! To the game of... ROCK!! PAPER!! SCISSORS!!!!!!!" << endl << endl;
	cout << "IN THIS GAME!! YOU WILL SELECT YOUR TOOL WITH r, s OR p!!!!!" << endl;
	char prev = 'r';
	for (int t = 0; t < 50; t++)
	{
		cout << "prev = " << prev << endl;
		game.incturns();
		cout << endl << "ROUND " << game.getturns() << "!!" << endl << endl;
		cout << "HUMAN!! PICK YOUR TOOL!!!" << endl;
		char h;
		cin >> h;
		game.sethuman(h);
		cout << "YOU HAVE SELECTED... " << game.gethuman()->gettype() << "!!!" << endl;
		cout << "Round " << game.getturns() << "....... FIGHT!!!!!" << endl;
		int res;
		if (game.gethuman()->gettype() == 'r') { prev = play_rock(game, res, prev); }
		if (game.gethuman()->gettype() == 'p') { prev = play_paper(game, res, prev); }
		if (game.gethuman()->gettype() == 's') { prev = play_scissors(game, res, prev); }
		show_scores(game);
	}
	return 0;
}