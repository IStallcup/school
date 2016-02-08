#ifndef GAME_H
#define GAME_H

class tool
{
	public:
		void setstr(int);
		void settype(char);
		
		int get_str();
		char get_type();
	private:
		int str;
		char type;
};

class rpsgame
{
	public:
		void set_meat(int, char);
		void set_comp(int, char);	
		
		void test();
		
		tool* get_meat();
	private:
		tool *meat;
		tool *comp;
};



#endif