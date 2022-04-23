
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
//GetAsyncKeyStateȷ���û���ǰ�Ƿ����˼����ϵ�һ�����ĺ�����������£��򷵻�ֵ���λΪ1
			//KEY_DOWN(VK_LBUTTON)�ж����
			//KEY_DOWN(VK_RBUTTON)�ж��Ҽ�
			//KEY_DOWN(VK_MBUTTON)�жϹ���
#define PI 3.14159265359
#define random(x) (rand()%x)
#define N 8
#define M 3
long start_time;//��ʼʱ��
long overtime;//�Ѿ�������ʱ��
void gotoxy(int x, int y)//�Լ�����һ��gotoxy�����������x��y�� 
{
	COORD c;     //����һ�������
	c.X = x - 1; //�����������λ��
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);   //����WindowsAPI�����ù��λ��
}
void showtime()
{
	long t = time(0) - start_time;
	gotoxy(80, 10);//ָ��λ��
	cout << setw(2) << setfill('0') << t / 60 / 60 << ":"
		<< setw(2) << setfill('0') << t / 60 << ":"
		<< setw(2) << setfill('0') << t % 60 << endl;//���ʱ��
	overtime = t;

}
using namespace std;
POINT p;
int coord[9];//����ͼƬ������
int j;
int n;
int arr;//��ǰ��ָ��ͼƬ����
int arr1;//��һ�����ͼƬ����
int arr2;//�ڶ������ͼƬ����

//int thesecand;
//int thefirst;
int main() 
{
	HWND/*���ھ��*/ h = initgraph(600, 600, EW_SHOWCONSOLE);//���ɽ���
	setbkcolor(WHITE);				//����ɫ
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 3);
	setlinecolor(RED);

	IMAGE image[9]; //����һ��ͼƬ����
	IMAGE imageload[36];//�洢�ĸ�����ͼƬ
	Game xiaoxiaole;//�Զ�����
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
	xiaoxiaole.flag = 1;//�Ƿ�ʼ�ȶԣ�1Ϊ��ʼ 0Ϊ�ڶ���
	int T = 3;
	
	start_time = time(0);
	while (1)
	{
		showtime();
		GetCursorPos(&p);                       //��ȡ�������Ļ�ϵ�λ�� �������
		ScreenToClient(h, &p);                  //�ú�������Ļ��ָ�������Ļ����ת�����û����ꡣ
		arr = p.y / 200 * 3 + p.x / 200;
		xiaoxiaole.x = p.x / 200;
		xiaoxiaole.y = p.y / 200;

		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				putimage(200 * (i), 200 * (j), showimage + j * 3 + i);      //��ͼƬ��ŵ���ʾ�Ľ����У� ͼƬ��x�����꣬ͼƬy�����꣬ȡ���ͼƬ��ָ���ַ
			}
		}//������ͼƬ���������


		if (KEY_DOWN(VK_RBUTTON))//�Ҽ�
		{
			Sleep(20);//����
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
						//					printf("���� %d\n", coord[arr]);
											/*cout << "����"<<coord[arr] << endl;*/
						xiaoxiaole.flag = 1;
						T--;
					}
					else;
				}
			}

		};

		if (KEY_DOWN(VK_LBUTTON) && xiaoxiaole.flag == 1)//���
		{
			Sleep(50);//����
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
			
			Sleep(20);//ѭ��ʱ��������ֹ̫ռ�ڴ� 
			break;
					  //system("cls");//���� 
		}
		Sleep(20);
	}

	return 0;
}

