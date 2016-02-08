#include "./tools.h"
#include <iostream>

using namespace std;

//tool's default constructor
tool::tool()
{
	//cout << "Default constructor tool" << endl;
	str = 0;
	type = 'e';
}

//copy constructor for tool
tool::tool(const tool &o)
{
	str = o.str;
	type = o.type;
}

//destructor for tool
tool::~tool()
{
	//cout << "Destructor tool" << endl;
}

//assignment operator overload
void tool::operator=(const tool &o)
{
	str = o.str;
	type = o.type;
}

//sets strength to input strength
void tool::setstr(int i)
{
	str = i;
}

//returns the strength of the tool
int tool::getstr() const
{
	return str;
}

//returns the type of the tool
char tool::gettype() const
{
	return type;
}

//---------------rock---------------

//default constructor
rock::rock()
{
	//cout << "Default constructor rock" << endl;
	//setstr(1);
	str = 1;
	type = 'r';
}

//non-default constructor
rock::rock(int i)
{
	//cout << "Non-default constructor rock" << endl;
	//setstr(i);
	str = i;
	type = 'r';
}

//destructor
rock::~rock()
{
	//cout << "Destructor rock" << endl;
}

//assignment operator overload
void rock::operator=(const rock &o)
{
	str = o.str;
	type = o.type;
}

//Function: int rock::fight(tool t)
//Input: object t of type tool
//Output: win (1), loss (0) or tie (-1) result of
//	game of rock paper scissors between
//	the input type (computer's choice)
//	and rock

int rock::fight(tool com, tool human)
{
	cout << endl  << "\tHuman\t\tvs\t\tComp" << endl << endl;
	cout << "\tROCK\t\tvs\t\t";
		if (com.gettype() == 'r')
		{
			cout <<"ROCK" << endl << endl;
		}
		if (com.gettype() == 'p')
		{
			cout <<"PAPER" << endl << endl;
			com.setstr(2);
		}
		if (com.gettype() == 's')
		{
			cout <<"SCISSORS" << endl << endl;
			human.setstr(2);
		}
	if (com.getstr() > human.getstr())
	{
		cout << "The game is a LOSS." << endl;
		return 0;
	}
	if (human.getstr() > com.getstr())
	{
		cout << "The game is a WIN." << endl;
		return 1;
	}
	if (human.getstr() == com.getstr())
	{
		cout << "The game is a TIE." << endl;
		return 2;
	}
}

/*
int rock::fight(tool t)
{
	cout << "YOUR OPPONENT HAS SELECTED....";
	if (t.gettype() == 's')
	{
		cout << "SCISSORS!!!!" << endl;
		if (t.getstr() > (2*getstr())) {return 0;}
		if (t.getstr() < (2*getstr())) {return 1;}
		if (t.getstr() == getstr()) {return -1;}
	}
	if (t.gettype() == 'p')
	{
		cout << "PAPER!!!!" << endl;
		
		if ((2*t.getstr()) > getstr()) {return 0;}
		if ((2*t.getstr()) < getstr()) {return 1;}
		if (t.getstr() == getstr()) {return -1;}
	}
	if (t.gettype() == 'r')
	{
		cout << "ROCK AS WELL!!! COWARDS!!!" << endl;
		return -1;
	}
}
*/
//---------------paper---------------

//default constructor
paper::paper()
{
	//cout << "Default constructor paper" << endl;
	str = 1;
	type = 'p';
}

//non-default constructor
paper::paper(int i)
{
	//cout << "Non-default constructor paper" << endl;
	str = i;
	type = 'p';
}

//destructor
paper::~paper()
{
	//cout << "Destructor paper" << endl;
}

//assignment operator overload
void paper::operator=(const paper &o)
{
	str = o.str;
	type = o.type;
}

//Function: int paper::fight(tool t)
//Input: object t of type tool
//Output: win (1), loss (0) or tie (-1) result of
//	game of rock paper scissors between
//	the input type (computer's choice)
//	and paper

int paper::fight(tool com, tool human)
{
	cout << endl  << "\tHuman\t\tvs\t\tComp" << endl << endl;
	cout << "\tPAPER\t\tvs\t\t";
		if (com.gettype() == 'r')
		{
			cout <<"ROCK" << endl << endl;
			cout << "The game is a WIN." << endl;
			return 1;
		}
		if (com.gettype() == 'p')
		{
			cout <<"PAPER" << endl << endl;
			cout << "The game is a TIE." << endl;
			return 2;
		}
		if (com.gettype() == 's')
		{
			cout <<"SCISSORS" << endl << endl;
			cout << "The game is a LOSS." << endl;
			return 0;
		}
}

/* paper::fight(tool t)
{
	cout << "YOUR OPPONENT HAS SELECTED....";
	if (t.gettype() == 'r')
	{
		cout << "ROCK!!!!" << endl;
		if (t.getstr() > (2*getstr())) {return 0;}
		if (t.getstr() < (2*getstr())) {return 1;}
		if (t.getstr() == getstr()) {return -1;}
	}
	if (t.gettype() == 's')
	{
		cout << "SCISSORS!!!!" << endl;
		
		if ((2*t.getstr()) > getstr()) {return 0;}
		if ((2*t.getstr()) < getstr()) {return 1;}
		if (t.getstr() == getstr()) {return -1;}
	}
	if (t.gettype() == 'p')
	{
		cout << "PAPER AS WELL!!! COWARDS!!!" << endl;
		return -1;
	}
}
*/
//---------------scissors---------------

//default constructor
scissors::scissors()
{
	//cout << "Default constructor scissors" << endl;
	str = 1;
	type = 's';
}

//non-default constructor
scissors::scissors(int i)
{
	//cout << "Non-default constructor scissors" << endl;
	str = i;
	type = 's';
}

//destructor
scissors::~scissors()
{
	//cout << "Destructor scissors" << endl;
}

//assignment operator overload
void scissors::operator=(const scissors &o)
{
	str = o.str; 
	type = o.type;
}

//Function: int scissors::fight(tool t)
//Input: object t of type tool
//Output: win (1), loss (0) or tie (-1) result of
//	game of rock paper scissors between
//	the input type (computer's choice)
//	and scissors

int scissors::fight(tool com, tool human)
{
	cout << endl  << "\tHuman\t\tvs\t\tComp" << endl << endl;
	cout << "\tSCISSORS\t\tvs\t\t";
		if (com.gettype() == 'r')
		{
			cout <<"ROCK" << endl << endl;
			cout << "The game is a LOSS." << endl;
			return 0;
		}
		if (com.gettype() == 'p')
		{
			cout <<"PAPER" << endl << endl;
			cout << "The game is a WIN." << endl;
			return 1;
		}
		if (com.gettype() == 's')
		{
			cout <<"SCISSORS" << endl << endl;
			cout << "The game is a TIE." << endl;
			return 2;
		}
}

/*
int scissors::fight(tool t)
{
	cout << "YOUR OPPONENT HAS SELECTED....";
	if (t.gettype() == 'p')
	{
		cout << "PAPER!!!!" << endl;
		if (t.getstr() > (2*getstr())) {return 0;}
		if (t.getstr() < (2*getstr())) {return 1;}
		if (t.getstr() == getstr()) {return -1;}
	}
	if (t.gettype() == 'r')
	{
		cout << "ROCK!!!!" << endl;
		
		if ((2*t.getstr()) > getstr()) {return 0;}
		if ((2*t.getstr()) < getstr()) {return 1;}
		if (t.getstr() == getstr()) {return -1;}
	}
	if (t.gettype() == 's')
	{
		cout << "SCISSORS AS WELL!!! COWARDS!!!" << endl;
		return -1;
	}
}
*/
