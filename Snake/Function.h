#pragma once
#include <vector>
#include "Define.h"

using namespace std;

void initial(int &direct, vector<point> &body, int &score, int &level);//初始化
void CLear();//重新影印
void show(int score, int level);//顯示
void set_apple();//蘋果設定
bool snake(vector<point> &body, int direct, int &score);//蛇的身體變化
void move(vector<point> &body, int direct);//移動
bool keyboard(char command, vector<point> &body, int &direct);//鍵盤
bool hit_wall(vector<point> body);//撞牆判斷
int Getspeed(int level);
void getlevel(int score, int &level);