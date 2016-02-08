#ifndef ROOM_H
#define ROOM_H

class Floor
{
	public:
		Floor();
		~Floor();
		Floor(const char*, char**);
		const char* filename;
		int obj_row;
		int obj_col;
		char **plan;
	private:
};

class Roomba
{
	private:
		int battery;
		int total_moves;
	public:
		Roomba(char**);
};

class RandomRoomba:public Roomba
{
	private:
	public:
};

class DumbRoomba : public Roomba
{
};

class SmartRoomba : public Roomba
{
};

#endif