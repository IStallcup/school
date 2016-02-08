#ifndef GAME_H
#define GAME_H

#include "./tools.h"

class rps
{
	public:
		rps();
		~rps();
		rps(const rps &);
		
		void incturns();
		int getturns() const;
		
		int gethwins() const;
		int getcwins() const;
		int getties() const;
		
		void inchw();
		void inccw();
		void inct();
		
		
		void sethuman(char);
		tool* gethuman() const;
		
	private:		
		int human_wins;
		int computer_wins;
		int ties;
		int turns;
		
		tool *human;
		tool *comp;
};

void play_rock(rps &, int);
void play_paper(rps &, int);
void play_scissors(rps &, int);

#endif