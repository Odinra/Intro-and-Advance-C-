/*CK King
section 1031
Start Time 07/12/12 20:01 - End Time 07/12/12 */
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

class shape
{
private: 
	int xDir, yDir;
public:
	virtual void setDirection(int xdir, int ydir)
	{
		xDir = xdir;
		yDir = ydir;
	}
	void getDirection(int &xdir, int &ydir)
	{ 
		xdir = xDir;
		ydir = yDir;
	}
	virtual void move() = 0;
};

class simpleShape : public shape
{
private:
	int color;
	int xPos, yPos;
public:
	virtual void draw() = 0;
	void getPosition(int &x, int &y)
	{
		x = xPos;
		y = yPos;
	}
	void setPosition(int x, int y)
	{
		xPos = x;
		yPos = y;
	}
	void setColor(int c)
	{
		color = c;
	}
	int getColor()
	{
		return color;
	}
	virtual void move();
};

class Box : public simpleShape
{
private:
	int width, height;
public:
	virtual void draw();
	Box(int xPos, int yPos, int width, int height);
};