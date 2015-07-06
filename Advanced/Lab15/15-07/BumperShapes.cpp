/*CK King
section 1031
Start Time 07/12/12 20:01 - End Time 07/12/12 */
#include "BumperShapes.h"

void simpleShape::move()
{
	int xDir, yDir;
	int savedColor = color;
	color = 0;

	draw();

	getDirection(xDir, yDir);
	xPos += xDir;
	yPos += yDir;

	color = savedColor;
	draw();
}

void Box::draw()
{
	int xPos, yPos;
	COORD pos;

	SetConsoleTextAttribute(handle, getColor());

	getPosition(xPos, yPos);
	pos.X = xPos;
	pos.Y = yPos;

	for (int x = 0; x < height; x++)
	{
		SetConsoleCursorPosition(handle, pos);
		for (int y = 0; y < height; y++)
		{
			cout << "*";
		}
		cout << "\n";
		pos.Y++;
	}

	SetConsoleTextAttribute(handle, 7);
}

Box::Box(int xPos, int yPos, int width, int height)
{
	setColor(4);
	setPosition(xPos, yPos);
	this->width = width;
	this->height = height;
	draw();
}