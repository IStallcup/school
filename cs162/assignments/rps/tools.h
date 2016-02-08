#ifndef TOOLS_H
#define TOOLS_H

class tool
{
	public:
		tool();
		tool(const tool &);
		~tool();
		void operator=(const tool &);
		
		void setstr(int);
		
		int getstr() const;
		char gettype() const;
	protected:
		int str;
		char type;
	
};

class rock : public tool
{
	public:
		rock();
		rock(int);
		~rock();
		
		void operator=(const rock &);
		
		int fight(tool, tool);
};

class paper : public tool
{
	public:
		paper();
		paper(int);
		~paper();
		
		void operator=(const paper &);
		
		int fight(tool, tool);
};

class scissors : public tool
{
	public:
		scissors();
		scissors(int);
		~scissors();
		
		void operator=(const scissors &);
		
		int fight(tool, tool);
};

#endif