/*CK King
section 1031
Start Time 07/12/12 20:01 - End Time 07/12/12 */
#include "BumperShapes.h"
int main()
{
	Box box(1, 0, 7, 7);
	Box box2(72,0,7,7);

	box2.setColor(3);
	box.draw();
	box2.draw();

	int x1,y1,x2,y2;

	int box1dir = 1;
	int box2dir = -1;

	box.setDirection(box1dir,0);
	box2.setDirection(box2dir,0);
	for(int meet = 0; meet < 10;)
	{
		box.getPosition(x1, y1);
		box2.getPosition(x2, y2);
		if (x1  < 1)
		{
			box1dir *= -1;
			box.setDirection(box1dir, 0);
		}

		if (x2 > 72)
		{
			box2dir *= -1;
			box2.setDirection(box2dir, 0);
		}

		if (x1 + 7 >= x2)
		{
			box1dir *= -1;
			box.setDirection(box1dir, 0);
			box2dir *= -1;
			box2.setDirection(box2dir, 0);
			meet++;
		}

		Sleep(10);
		box.move();
		box2.move();
	}
	system("pause");
	return 0;
}