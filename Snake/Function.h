#pragma once
#include <vector>
#include "Define.h"

using namespace std;

void initial(int &direct, vector<point> &body, int &score, int &level);//��l��
void CLear();//���s�v�L
void show(int score, int level);//���
void set_apple();//ī�G�]�w
bool snake(vector<point> &body, int direct, int &score);//�D�������ܤ�
void move(vector<point> &body, int direct);//����
bool keyboard(char command, vector<point> &body, int &direct);//��L
bool hit_wall(vector<point> body);//����P�_
int Getspeed(int level);
void getlevel(int score, int &level);