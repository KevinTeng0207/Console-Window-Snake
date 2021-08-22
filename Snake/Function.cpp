#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "console.h"
#include "Function.h"
using namespace std;

int map[map_y][map_x];
void initial(int &direct, vector<point> &body, int &score, int &level)
{
	for (int i = 0; i < map_y; i++)
	{
		for (int j = 0; j < map_x; j++)
		{
			if (i == 0 || i == map_y - 1)
				map[i][j] = 6;
			else if(j == 0 || j == map_x - 1)
				map[i][j] = 6;
			else
				map[i][j] = 0;
		}
	}
	score = 0;
	getlevel(score, level);
	point head;
	head.y = 5;
	head.x = 5;
	head.direct = E;
	body.push_back(head);
	point head2;
	head2.y = 5;
	head2.x = 4;
	head2.direct = E;
	direct = E; 
	body.push_back(head2);
	point head3;
	head3.y = 5;
	head3.x = 3;
	head3.direct = E;
	direct = E;
	body.push_back(head3);
	map[body[0].y][body[0].x] = 9;	
	map[body[1].y][body[1].x] = 8;
	map[body[2].y][body[2].x] = 8;
}
void CLear()
{
	for (int i = 0; i < map_y; i++)
	{
		for (int j = 0; j < map_x; j++)
		{
			if (map[i][j] == 5)
				continue;
			else if (map[i][j] == 6)//邊界
				continue;
			else
				map[i][j] = 0;
		}
	}
}
void show(int score, int level)
{
	Set_OUTPUTpos(0, 5); 
	for (int i = 0; i < map_y; i++)
	{		
		Set_OUTPUTpos(30, i + 5);
		for (int j = 0; j < map_x; j++)
		{
			switch (map[i][j])
			{
			case 0://apple
			#ifdef debug
				cout << 0;
			#else
				cout << "  ";
			#endif
				break;
			case 6://boundary
			#ifdef debug
				cout << "6";
			#else
				SetColor(8);
				cout << "※";
				SetColor(7);
			#endif
				break;
			case 5://apple
			#ifdef debug
				cout << 5;
			#else
				SetColor(6);
				cout << "★";
				SetColor(7);
			#endif 
				break;
			case 8://snake_body
			#ifdef debug
				cout << 8;
			#else
				SetColor(3);
				cout << "●";
				SetColor(7);
			#endif 
				break;
			case 9://snake_head
				#ifdef debug
					cout << 9;
				#else
					SetColor(10);
					cout << "■";
					SetColor(7);
				#endif
				break;
			}
		}
		cout << "\n";
	}
	Set_OUTPUTpos(100, 5);
	printf("Level:  %3d", level);
	Set_OUTPUTpos(100, 6);
	cout << "------------";
	Set_OUTPUTpos(100, 8);	
	printf("Score:  %03d", score);
	Set_OUTPUTpos(100, 9);
	cout << "------------";
}

void set_apple()
{
	point apple;
	do
	{
		apple.y = rand() % map_y;
		apple.x = rand() % map_x;
	} while (map[apple.y][apple.x] != 0);
	
	map[apple.y][apple.x] = 5;
}
bool snake(vector<point> &body, int direct, int &score)
{
	point tmp;
	bool eat_apple = false;
	if (map[body[0].y][body[0].x] == 5)
	{
		eat_apple = true;
		score += 1;
		tmp.y = body[body.size() - 1].y;
		tmp.x = body[body.size() - 1].x;
		tmp.direct = body[body.size() - 1].direct;
		switch (body[body.size() - 1].direct)
		{
		case N://北
			++tmp.y;
			break;
		case E://東
			--tmp.x;
			break;
		case S://南
			--tmp.y;
			break;
		case W://西
			++tmp.x;
			break;
		}
		if (map[tmp.y][tmp.x] != 0)
		{
			tmp.y = body[body.size() - 1].y;
			tmp.x = body[body.size() - 1].x;
			switch (body[body.size() - 1].direct)
			{
			case N://北
				--tmp.x;
				tmp.direct = E;
				break;
			case E://東
				++tmp.y;
				tmp.direct = S;
				break;
			case S://南
				++tmp.x;
				tmp.direct = W;
				break;
			case W://西
				++tmp.y;
				tmp.direct = N;
				break;
			}
		}
			
		body.push_back(tmp);
	}
		
	for (int i = 0; i < body.size(); i++)
	{
		if (i == 0)
			map[body[i].y][body[i].x] = 9;
		else
			map[body[i].y][body[i].x] = 8;
	}
	return eat_apple;
}

void move(vector<point> &body, int direct)
{
	point old,tmp;
	old.x = body[0].x;
	old.y = body[0].y;
	old.direct = body[0].direct;
	switch (body[0].direct)
	{
	case N://北
		--body[0].y; 
		break;
	case E://東
		++body[0].x;
		break;
	case S://南
		++body[0].y;
		break;
	case W://西
		--body[0].x;
		break;
	}
	for (int i = 1; i < body.size(); i++)
	{
		tmp.x = old.x;
		tmp.y = old.y;
		tmp.direct = old.direct;
		old.x = body[i].x;
		old.y = body[i].y;
		old.direct = body[i].direct;
		body[i].x = tmp.x;
		body[i].y = tmp.y;
		body[i].direct = tmp.direct;
	}
}
bool keyboard(char command,vector<point> &body, int &direct)
{
	bool change = false;
	switch (direct)
	{
	case E:
		switch (command)
		{
		case 72:
			direct = N;
			body[0].direct = N;
			change = true;
			break;
		case 80:
			direct = S;
			body[0].direct = S;
			change = true;
			break;
		}
		break;
	case W:
		switch (command)
		{
		case 72:
			direct = N;
			body[0].direct = N;
			change = true;
			break;
		case 80:
			direct = S;
			body[0].direct = S;
			change = true;
			break;
		}
		break;
	case N:
		switch (command)
		{
		case 75:
			direct = W;
			body[0].direct = W;
			change = true;
			break;
		case 77:
			direct = E;
			body[0].direct = E;
			change = true;
			break;
		}
		break;
	case S:
		switch (command)
		{
		case 75:
			direct = W;
			body[0].direct = W;
			change = true;
			break;
		case 77:
			direct = E;
			body[0].direct = E;
			change = true;
			break;
		}
		break;
	}
	return change;
}

bool hit_wall(vector<point> body) 
{
	if (map[body[0].y][body[0].x] == 6 || map[body[0].y][body[0].x] == 8)
		return false;
	else
		return true;
}

int Getspeed(int level)
{
	switch(level)
	{
	case 1:
		return level1;
		break;
	case 2:
		return level2;
		break;
	case 3:
		return level3;
		break;
	case 4:
		return final;
		break;
	}
}

void getlevel(int score, int &level)
{
	if (score < 10)
		level = 1;
	else if (score >= 10 && score < 60)
		level = 2; 
	else if (score >= 60 && score < 200)
		level = 3;
	else if (score >= 200)
		level = 4;
}