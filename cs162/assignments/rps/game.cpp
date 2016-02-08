#include "./game.h"
#include "./tools.h"
#include <iostream>
#include <cstdlib>

using namespace std;

rps::rps() //default constructor
{
	//cout << "Default constructor rps" << endl;
	comp = NULL;
	human = NULL;
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
	turns = 0;
}

rps::~rps() //destructor
{
	//cout << "Destructor rps" << endl;
	delete comp;
	delete human;
}

//copy constructor
rps::rps(const rps &o)
{
	human_wins = o.human_wins;
	computer_wins = o.computer_wins;
	ties = o.ties;
	turns = o.turns;
	human = o.human;
	comp = o.comp;
}
void rps::operator=(const rps &o)
{
	human_wins = o.human_wins;
	computer_wins = o.computer_wins;
	ties = o.ties;
	turns = o.turns;
	human = o.human;
	comp = o.comp;
}

tool* rps::getcomp() const
{
	return comp;
}

tool* rps::gethuman() const
{
	return human;
}

//sets up human to be of the type requested
void rps::sethuman(char i) 
{
	while (i != 'r' && i != 'p' && i != 's' && i != 'e')
	{
		cout << "Invalid input." << endl;
		cout << "Select your tool.\t\t";
		cin >> i;
	}
	if (i == 'r')
	{
		human = new rock;
	}
	if (i == 'p')
	{
		human = new paper;
	}
	if (i == 's')
	{
		human = new scissors;
	}
	if (i == 'e')
	{
		cout << "Goodbye." << endl;
		exit(0);
	}
}

void rps::incturns()
{
	turns++;
}

int rps::getturns() const
{
	return turns;
}

int rps::gethwins() const
{
	return human_wins;
}

int rps::getcwins() const
{
	return computer_wins;
}

int rps::getties() const
{
	return ties;
}

void rps::inchw()
{
	human_wins++;
}

void rps::inccw()
{
	computer_wins++;
}

void rps::inct()
{
	ties++;
}