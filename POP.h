#pragma once
#include<iostream>
#include<windows.h>
#include <easyx.h>
#include <graphics.h>
#include<conio.h>
#include <iomanip>
#define N 8

//char str1[100] = "D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/";
//char str2[10] = ".jpg";



using namespace std;
class Game
{

public:
	IMAGE image[9];
	IMAGE imagebuf[9];
	int width;
	int longth;
	int x;
	int y;
	int x1;
	int y1;
	int x2;
	int y2;
	int flag;

	void imageload(IMAGE* image, int width, int longth)
	{
	/*	for (int i = 0; i <= N; i++)
		{

			strcpy_s(str3, str1);
			sprintf_s(str4, "%d", i);
			strcat_s(str3, str4);
			strcat_s(str3, str2);
			str[i] = str3;
			printf("%s\n", str3);
			LPCTSTR w = (const char*)(str3);
			loadimage(&image[i], w, width, longth);
		}*/
	loadimage(&image[0], _T("D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/1.jpg"), width, longth);  //È¡Ó³ÏñÖ¸Õë£¬Í¼Æ¬Â·¾¶£¬Í¼Æ¬µÄxÖá×ø±ê£¬Í¼Æ¬yÖá×ø±ê
	loadimage(&image[1], _T("D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/2.jpg"), width, longth);
	loadimage(&image[2], _T("D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/3.png"), width, longth);
	loadimage(&image[3], _T("D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/4.jpg"), width, longth);
	loadimage(&image[4], _T("D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/5.png"), width, longth);
	loadimage(&image[5], _T("D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/6.jpg"), width, longth);
	loadimage(&image[6], _T("D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/7.jpg"), width, longth);
	loadimage(&image[7], _T("D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/8.jpg"), width, longth);
	loadimage(&image[8], _T("D:/Microsoft Visual Studio2019/program/C or Cpp/CPP/xiaoxiaole/xiaoxiaole/photo/9.jpg"), width, longth);

	}

};
