#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Function.h"
#include "console.h"

int main()
{
	int direct;
	int score, level;
	bool flag = true;
	vector<point> body;
	unsigned long times;
	srand((unsigned int)time(NULL));
	//Hide_Cursor();
	//Correct_color();
	//SetConsoleSize(100, 250);
	initial(direct, body, score, level);
	set_apple();
	while (hit_wall(body))
	{
		CLear();
		if (snake(body, direct, score))
			set_apple();
		show(score, level);
		getlevel(score, level);
		times = GetTickCount();
		do
		{
			if (flag)
				if (_kbhit())
					if (keyboard(_getch(), body, direct))
						flag = false;
		}while (GetTickCount() - times <= Getspeed(level));
		flag = true;
		move(body, direct);	
	}

	return 0;
}