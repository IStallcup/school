#ifndef PAPER_H
#define PAPER_H

#include "./game.h"

class paper : public tool
{
	public:
		paper() : tool(){setstr(1);}
};

#endif