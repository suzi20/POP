
#include <iostream>
#include <windows.h>
#include <easyx.h>
#include <graphics.h>
#include <conio.h>
#include "POP.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
//GetAsyncKeyState确定用户当前是否按下了键盘上的一个键的函数。如果按下，则返回值最高位为1
			//KEY_DOWN(VK_LBUTTON)判断左键
			//KEY_DOWN(VK_RBUTTON)判断右键
			//KEY_DOWN(VK_MBUTTON)判断滚轮
#define PI 3.14159265359
#define random(x) (rand()%x)
#define N 8
#define M 3
long start_time;//开始时刻
long overtime;//已经经过的时间
void gotoxy(int x, int y)//自己定义一个gotoxy，将光标跳到x列y行 
{
	COORD c;     //定义一个光标类
	c.X = x - 1; //设置这个光标的位置
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);   //调用WindowsAPI来设置光标位置
}
void showtime()
{
	long t = time(0) - start_time;
	gotoxy(80, 10);//指定位置
	cout << setw(2) << setfill('0') << t / 60 / 60 << ":"
		<< setw(2) << setfill('0') << t / 60 << ":"
		<< setw(2) << setfill('0') << t % 60 << endl;//输出时间
	overtime = t;

}
using namespace std;
POINT p;
int coord[9];//九张图片的坐标
int j;
int n;
int arr;//当前所指向图片坐标
int arr1;//第一次左键图片坐标
int arr2;//第二次左键图片坐标

//int thesecand;
//int thefirst;
int main() 
{
	HWND/*窗口句柄*/ h = initgraph(600, 600, EW_SHOWCONSOLE);//生成界面
	setbkcolor(WHITE);				//背景色
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 3);
	setlinecolor(RED);

	IMAGE image[9]; //定义一个图片变量
	IMAGE imageload[36];//存储四个方向图片
	Game xiaoxiaole;//自定义类
	xiaoxiaole.imageload(image,200,200);
	for (int i = 0; i < 9; i++)
	{
		rotateimage(imageload + (i * 4) + 0, image + i, 0);
		rotateimage(imageload + (i * 4) + 1, image + i, PI * 3 / 2);
		rotateimage(imageload + (i * 4) + 2, image + i, PI);
		rotateimage(imageload + (i * 4) + 3, image + i, PI / 2);
	}	
	IMAGE showimage[9];
	srand((unsigned)time(0));
	for (int i = 0; i < 9; i++)
	{
		int n = random(36);
		showimage[i] = imageload[n];
		coord[i] = n;
	}
	int score_all = 0;
	int x = 1;
	double score=0;
	xiaoxiaole.flag = 1;//是否开始比对，1为开始 0为第二次
	int T = 3;
	
	start_time = time(0);
	while (1)
	{
		showtime();
		GetCursorPos(&p);                       //获取鼠标在屏幕上的位置 鼠标坐标
		ScreenToClient(h, &p);                  //该函数把屏幕上指定点的屏幕坐标转换成用户坐标。
		arr = p.y / 200 * 3 + p.x / 200;
		xiaoxiaole.x = p.x / 200;
		xiaoxiaole.y = p.y / 200;

		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				putimage(200 * (i), 200 * (j), showimage + j * 3 + i);      //将图片存放到显示的界面中， 图片的x轴坐标，图片y轴坐标，取存放图片的指针地址
			}
		}//将九张图片输出按次序


		if (KEY_DOWN(VK_RBUTTON))//右键
		{
			Sleep(20);//消抖
			if (KEY_DOWN(VK_RBUTTON))
			{
				/*cout << "down\n" << endl;*/
				if (arr >= 0 && arr <= 8)
				{
					if (T) {
						if ((coord[arr] + 1) % 4 == 0)
							coord[arr] = coord[arr] - 3;
						else
							coord[arr]++;
						showimage[arr] = imageload[coord[arr]];
						//					printf("坐标 %d\n", coord[arr]);
											/*cout << "坐标"<<coord[arr] << endl;*/
						xiaoxiaole.flag = 1;
						T--;
					}
					else;
				}
			}

		};

		if (KEY_DOWN(VK_LBUTTON) && xiaoxiaole.flag == 1)//左键
		{
			Sleep(50);//消抖
			if (KEY_DOWN(VK_LBUTTON)) {
				arr1 = arr;
				xiaoxiaole.x1 = xiaoxiaole.x;
				xiaoxiaole.y1 = xiaoxiaole.y;
				srand((unsigned)time(0));
				n = random(36);
				xiaoxiaole.flag = 0;
				//printf("n %d\n", n);
				/*cout << "n " << n <<endl;
				cout << "coord[arr1] " << coord[arr1] << endl;*/
				//printf("coord[arr1] %d\n", coord[arr1]);
			}
		}
		int arr2 = p.y / 200 * 3 + p.x / 200;
		if (KEY_DOWN(VK_LBUTTON) && (arr2 != arr1) && (xiaoxiaole.flag == 0))
		{
			xiaoxiaole.x2 = p.x / 200;
			xiaoxiaole.y2 = p.y / 200;
			//printf("coord[arr2] %d\n", coord[arr2]);
			/*cout << "coord[arr2] " << coord[arr2] << endl;*/
			if ((coord[arr1] == coord[arr2]))
			{

				//printf("n %d\n", n);
				/*cout << "i " << n << endl;
				cout << "j " << j << endl;*/
				//printf("j %d\n", j);
				showimage[arr1] = imageload[n];
				coord[arr1] = n;
				srand((unsigned)time(0) + 12);
				j = random(36);
				showimage[arr2] = imageload[j];
				coord[arr2] = j;
				/*cout << "arr1 " << arr1 << endl;
				cout << "arr2 " << arr2 << endl;*/
				//printf("arr1 %d\n", arr1);
				//printf("arr2 %d\n", arr2);
				score = pow(2, x);
				score_all += (int)score;
				printf("score is %d\n", score_all);
				x++;
				T = T + 2 * x;
			}
			else x = 1;
			xiaoxiaole.flag = 1;
		}
		if (overtime > 59) {
			printf("GAME OVER!!!\n");
			printf("Your score is %d\n", score_all);
			
			Sleep(20);//循环时间间隔，防止太占内存 
			break;
					  //system("cls");//清屏 
		}
		Sleep(20);
	}

	return 0;
}

