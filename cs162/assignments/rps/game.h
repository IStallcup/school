#ifndef GAME_H
#define GAME_H

#include "./tools.h"

class rps
{
	public:
		rps();
		~rps();
		
		rps(const rps &);
		void operator=(const rps &);
		
		int getturns() const;
		int gethwins() const;
		int getcwins() const;
		int getties() const;
		
		void incturns();
		void inchw();
		void inccw();
		void inct();
		
		void sethuman(char);
		
		tool* gethuman() const;
		tool* getcomp() const;
		
	private:		
		int human_wins;
		int computer_wins;
		int ties;
		int turns;
		tool *human;
		tool *comp;
};

void play_game();
char play_rock(rps &, int, char);
char play_paper(rps &, int, char);
char play_scissors(rps &, int, char);
void show_scores(rps &);

#endif