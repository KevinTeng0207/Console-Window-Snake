#pragma once

void Set_OUTPUTpos(int x, int y);//移動光標
void Hide_Cursor();//隱藏光標
void SetColorRGB(int want_colorPOS, int R, int G, int B);//換顏色
void SetColor(int color);
void Correct_color();
bool SetConsoleSize(int w, int h);