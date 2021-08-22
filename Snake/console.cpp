#pragma once
#include <windows.h>
#include "console.h"

using namespace std;


void Set_OUTPUTpos(int x, int y)
{
	COORD point;
	point.X = x;
	point.Y = y;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//設置標準輸入	
	SetConsoleCursorPosition(hOut, point);
}

void Hide_Cursor()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(hOut, &cci);
}

void SetColorRGB(int want_colorPOS, int R, int G, int B)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX csbiInfo;
	csbiInfo.cbSize = sizeof(csbiInfo);
	GetConsoleScreenBufferInfoEx(hout, &csbiInfo);
	csbiInfo.ColorTable[want_colorPOS] = RGB(R, G, B);
	SetConsoleScreenBufferInfoEx(hout, &csbiInfo);
	SetConsoleTextAttribute(hout, want_colorPOS);
}
void SetColor(int color)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, color);
}
void Correct_color()
{
	SetColorRGB(1, 22, 100, 105);	//藍色
	SetColorRGB(2, 150, 255, 77);	//綠色
	SetColorRGB(3, 22, 230, 255);	//青色
	SetColorRGB(4, 244, 30, 40);	//紅色
	SetColorRGB(5, 217, 77, 205);	//紫色
	SetColorRGB(6, 255, 200, 0);	//黃色
		/**********額外**********/
	SetColorRGB(14, 245, 128, 31);	//橘色
	SetColorRGB(11, 169, 169, 169);	//灰色
	SetColorRGB(13, 204, 204, 255);	//長春花色
}

bool SetConsoleSize(int W, int H)
{
	BOOL ret;
	SMALL_RECT SR;
	SR.Top = 0;
	SR.Left = 0;
	SR.Bottom = H - 1;
	SR.Right = W - 1;
	ret = SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &SR);
	if (!ret)
		return ret;
	COORD Sz;
	Sz.X = W;
	Sz.Y = H;
	return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), Sz);
}