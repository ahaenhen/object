#include<graphics.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#include<atlimage.h>
#include<iostream>
#include<string>
#include<fstream>
#include<mciapi.h>
#pragma comment(lib,"winmm.lib")
#define blue RGB(0, 25, 250)
#define pink RGB(148, 91, 142)
#define mi RGB(255,251,216)
using namespace std;
const int MAX = 200;
int score = 0, speed = 400, record, jiemian;
bool sexy,play=1,mode=1;
TCHAR s[5];
IMAGE backimage, right1_head, left1_head, up_head, down_head, body, food;
IMAGE over1, zhuan, back0, back, musicimage, choose, set, zhe;
MOUSEMSG msg;

void welcome();
void drowsnake();
void initgame();
void movesnake();
void Changedirebykb();
void foodcoor();
void drawcake();
void eat();
int breaksnake();
void overgame();
void choosegender();
void menujiemian();
void Save();
void scoreprint();
void playgame();
void playgame2();
void bfs();
void Read();
void Save();
void ChangeDireByMouse(const int &x,const int &y);
DWORD proc(LPVOID IpThreadParameter),pid;

enum DIRE   //方向
{
	up = 72,
	down = 80,
	left1 = 75,
	right1 = 77
};

 struct COOR			//坐标
{
	int x;
	int y;
};
 COOR past[6];
struct Snake       //蛇
{
	int n;              //当前节数
	COOR src[MAX];		
	DIRE dire;
}snake,group[5];
struct Food			//食物
{
	COOR food;
	bool flag;
}cake;

int main()
{
	initgraph(900, 600);
	choosegender();
	loadimage(&right1_head, L".\\image\\right1.jpg", 15, 15);
	loadimage(&left1_head, L".\\image\\left1.jpg", 15, 15);
	loadimage(&up_head, L".\\image\\up.jpg", 15, 15);
	loadimage(&down_head, L".\\image\\down.jpg", 15, 15);
	loadimage(&body, L".\\image\\body.jpg", 15, 15);
	loadimage(&food, L".\\image\\food.jpg", 15, 15);
	loadimage(&zhe, L".\\image\\zhe.jpg", 15, 15);
	if (sexy)
		loadimage(&zhuan, L".\\image\\砖.jpg", 20, 20);
	else
		loadimage(&zhuan, L".\\image\\砖2.jpg", 20, 20);
	mciSendString(L"play scg repeat", NULL, 0, NULL);
	aa:
	welcome();
	if (jiemian == 1)
	{
		bb:
		if(mode==1)
			playgame();
		else 
			playgame2();
		overgame();
		if (jiemian == 1)
		{
			goto bb;
		}
		else if(jiemian == 0)
		{
			goto aa;
		}
	}
	else
	{
		menujiemian();
		if (jiemian == 0)
		{
			goto aa;
		}
	}
	getchar();
	return 0;
}
void playgame()
{
	initgame();
	if (sexy)
		loadimage(&back0, L".\\image\\back1.jpg", 900, 600);
	else
		loadimage(&back0, L".\\image\\back0.jpg", 900, 600);
	putimage(0, 0, &back0);
	for (int i = 10; i <= 570; i += 20)
		putimage(i, 10, &zhuan);
	for (int i = 10; i <= 570; i += 20)
		putimage(i, 570, &zhuan);
	for (int i = 10; i <= 570; i += 20)
		putimage(10, i, &zhuan);
	for (int i = 10; i <= 570; i += 20)
		putimage(570, i, &zhuan);
	if (sexy)
	{
		settextcolor(blue);
	}
	else
	{
		settextcolor(pink);
	}
	settextstyle(40, 0, L"Ink Free");
	outtextxy(700, 35, L"score:");
	_stprintf_s(s, _T("%d"), record);
	outtextxy(800, 155, s);
	outtextxy(700, 155, L"record:");
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, NULL, 0, &pid);
	while (1)
	{
		while (!_kbhit())
		{
			if (cake.flag == 0)
				foodcoor();
			if (breaksnake())
				return;
			movesnake();
			drawcake();
			drowsnake();
			eat();
			if (cake.flag == 0)
			{
				scoreprint();
			}
			Sleep(speed);
		}
		Changedirebykb();
	}
}
void playgame2()
{
	initgame();
	cleardevice();
	setbkcolor(mi);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; i++)
	{
		group[i].n = 4;
		group[i].dire = right1;
		score = 0;
		Read();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (j == 0)
				{
					group[i].src[j].x = rand() % 28 * 15 + 90;
					group[i].src[j].y = rand() % 28 * 15 + 45;
				}
				else
				{
					group[i].src[j].x = group[i].src[0].x - 15 * j;
					group[i].src[j].y = group[i].src[0].y;
				}
			}
			
		}
		cake.flag = 0;
	}
	if (sexy)
	{
		settextcolor(blue);
	}
	else
	{
		settextcolor(pink);
	}
	settextstyle(40, 0, L"Ink Free");
	outtextxy(0, 0, L"score:");
	//_stprintf_s(s, _T("%d"), record);
	//outtextxy(50, 0, s);
	outtextxy(50, 0, L"record:");
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, NULL, 0, &pid);
	while (1)
	{
		while (!_kbhit())
		{
			if (cake.flag == 0)
				foodcoor();
			if (breaksnake())
				return;
			movesnake();
			//bfs();
			drawcake();
			drowsnake();
			eat();
			//if (cake.flag == 0)
			//{
			//	//scoreprint();
			//}
			Sleep(speed);
		}
		Changedirebykb();
	}
}
void bfs() 
{


}
void welcome() 
{	
	cleardevice();
	setbkmode(TRANSPARENT);
	if (sexy == 1)
	{
		loadimage(&backimage, L".\\image\\start1.jpg", 900, 600);
	}
	else
	{
		loadimage(&backimage, L".\\image\\start2.jpg", 900, 600);
	}
	putimage(0, 0, &backimage);
	while (1) 
	{	
		settextstyle(180, 45, L"Taco Salad");
		outtextxy(20, 10, L" GREEDY  SNAKE");
		msg = GetMouseMsg();
		settextstyle(100, 0, L"Taco Salad");
		if (msg.x >= 350 && msg.x <= 580 && msg.y >= 200 && msg.y <= 300) 
		{
			if(sexy==1)
				settextcolor(pink);
			else 
				settextcolor(blue);
			outtextxy(350, 200, L"Begin");
		}
		else if (msg.x >= 370 && msg.x <= 550 && msg.y >=325 && msg.y <= 425)
		{
			if (sexy == 1)
				settextcolor(pink);
			else
				settextcolor(blue);
			outtextxy(370, 325, L"menu");
		}
		else if (msg.x >= 370 && msg.x <= 550 && msg.y >= 450 && msg.y <= 550)
		{
			if (sexy == 1)
				settextcolor(pink);
			else
				settextcolor(blue);
			outtextxy(370, 450, L"over");
		}
		else
		{
			if (sexy == 1)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(350, 200, L"Begin");
			outtextxy(370, 325, L"menu");
			outtextxy(370, 450, L"over");
		}
		
		switch (msg.uMsg) 
		{
			case WM_LBUTTONDOWN:
				if (msg.x >= 350 && msg.x <= 580 && msg.y >= 200 && msg.y <= 300) 
				{
					jiemian = 1;
					return;
				}
				else if (msg.x >= 370 && msg.x <= 550 && msg.y >= 325 && msg.y <= 425)
				{
					jiemian = 2;
					return;
				}
				else if (msg.x >= 370 && msg.x <= 550 && msg.y >= 450 && msg.y <= 550) 
				{
					exit(0);
					return;
				}
				break;
			default: break;
		}
	}
}
void drowsnake()
{
	IMAGE head;
	if (snake.dire == 72)head = up_head;
	else if (snake.dire == 80)head = down_head;
	else if (snake.dire == 75)head = left1_head;
	else head = right1_head;
	putimage(snake.src[0].x, snake.src[0].y, 15, 15, &head, 0, 0);
	putimage(snake.src[1].x, snake.src[1].y, 15, 15, &body, 0, 0);
	putimage(past[5].x, past[5].y, 15, 15, &zhe, 0, 0);
	past[5].x = snake.src[snake.n - 1].x;
	past[5].y = snake.src[snake.n - 1].y;
	if(!mode)
	{
		for (int i = 0; i < 3; i++)
		{
			if (group[i].dire == 72)head = up_head;
			else if (group[i].dire == 80)head = down_head;
			else if (group[i].dire == 75)head = left1_head;
			else head = right1_head;
			putimage(group[i].src[0].x, group[i].src[0].y, 15, 15, &head, 0, 0);
			putimage(group[i].src[1].x, group[i].src[1].y, 15, 15, &body, 0, 0);
			putimage(past[i].x, past[i].y, 15, 15, &zhe, 0, 0);
			past[i].x = group[i].src[group[i].n - 1].x;
			past[i].y = group[i].src[group[i].n - 1].y;
		}
	}
}
void initgame()
{
	cleardevice();
	srand((unsigned int)time(NULL));
	snake.n = 4;
	snake.dire = right1;
	score = 0;
	Read();
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			snake.src[i].x = rand() % 28*15 + 90;
			snake.src[i].y = rand() % 28*15+ 45;
		}
		else
		{
			snake.src[i].x = snake.src[0].x - 15 * i;
			snake.src[i].y = snake.src[0].y;
		}
	}
	cake.flag = 0;
}
void movesnake()
{
	for (int i = snake.n - 1; i > 0; i--) {
		snake.src[i].x = snake.src[i - 1].x;
		snake.src[i].y = snake.src[i - 1].y;
	}
	switch (snake.dire) {
	case up:
		snake.src[0].y -= 15;
		break;
	case down:
		snake.src[0].y += 15;
		break;
	case left1:
		snake.src[0].x -= 15;
		break;
	case right1:
		snake.src[0].x += 15;
		break;
	default:break;
	}
}
void Changedirebykb()
{
	int movech;
	movech = getch();
	switch (movech)
	{
	case up:
		if (snake.dire == up)
			speed -= 40;
		if(snake.dire!=down)
			snake.dire = up;
		else
			speed += 40;
		break;
	case down:
		if (snake.dire == down)
			speed -= 40;
		if (snake.dire != up)
			snake.dire = down;
		else
			speed += 40;
		break;
	case left1:
		if (snake.dire == left1)
			speed -= 40;
		if (snake.dire != right1)
			snake.dire = left1;
		else
			speed += 40;
		break;
	case right1:
		if (snake.dire == right1)
			speed -= 40;
		if (snake.dire != left1)
			snake.dire =right1;
		else
			speed += 40;
		break;
	default:break;
	}
	
}
void foodcoor()
{
	bb:
	cake.food.x = rand() %36* 15+30;
	cake.food.y = rand() %33* 15+30;
	for (int i = 0; i < snake.n; i++)
	{
		if (cake.food.x == snake.src[i].x&& cake.food.y == snake.src[i].y)
		{
			goto bb;
		}
	}
	cake.flag = 1;
}
void drawcake() 
{
	putimage(cake.food.x, cake.food.y, 20, 20, &food, 0, 0);
}
void eat(){
	if (snake.src[0].x == cake.food.x&&snake.src[0].y == cake.food.y)
	{
		snake.n++;
		cake.flag = 0;
		score++;
	}
	if(!mode)
	{
		for (int i = 0; i < 3; i++)
		{
			if (group[i].src[0].x == cake.food.x&&group[i].src[0].y == cake.food.y)
			{
				group[i].n++;
				cake.flag = 0;
				score++;
				break;
			}
		}
	}
}
int breaksnake()
{
	int t=0;
	if (mode)
	{
		if (snake.src[0].x <= 20 || snake.src[0].x >= 565 || snake.src[0].y <= 20 || snake.src[0].y >= 565)
		{
			t = 1;
		}
		for (int i = 1; i <= snake.n; i++){
			if (snake.src[0].x == snake.src[i].x&&snake.src[0].y == snake.src[i].y)
				t = 1;
		}
	}
	else
	{
		if (snake.src[0].x <= 0 || snake.src[0].x >= 900 || snake.src[0].y <= 0 || snake.src[0].y >= 600)
		{
			t = 1;
		}
		for (int i = 1; i <= snake.n; i++) 
		{
			if (snake.src[0].x == snake.src[i].x&&snake.src[0].y == snake.src[i].y)
				t = 1;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < group[i].n; j++)
			{
				if (snake.src[0].x == group[i].src[j].x&&snake.src[0].y == group[i].src[j].y)
					t = 1;
			}
			
		}
	}
	if (t)
		return 1;
	else
		return 0;
}
void overgame()
{
	Save();
	cleardevice();
	loadimage(&over1, L".\\image\\over1.jpg", 900, 600);
	putimage(0, 0, &over1);
	if (sexy == 1)
		settextcolor(blue);
	else
		settextcolor(pink);
	settextstyle(150, 45, L"Taco Salad");
	if (score <= record)
	{
		outtextxy(100, 400, L"keep on trying");
	}
	else
	{
		outtextxy(90, 400, L"break the record");
	}
	settextstyle(80, 0, L"Taco Salad");
	while (1)
	{
		msg = GetMouseMsg();
		if (msg.x >= 380 && msg.x <= 600 && msg.y >= 100 && msg.y <= 180)
		{
			if (sexy == 0)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(380, 100, L"again");
		}
		else if (msg.x >= 380 && msg.x <= 600 && msg.y >= 200 && msg.y <=280 )
		{
			if (sexy == 0)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(380, 200, L"over");
		}
		else if (msg.x >= 300 && msg.x <= 600 && msg.y >= 300 && msg.y <= 380)
		{
			if (sexy == 0)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(300, 300, L"home page");
		}
		else
		{
			if (sexy == 0)
				settextcolor(pink);
			else
				settextcolor(blue);
			outtextxy(380, 200, L"over");
			outtextxy(380, 100, L"again");
			outtextxy(300, 300, L"home page");
		}
		switch (msg.uMsg)
		{
		case WM_LBUTTONDBLCLK:
			if (msg.x >= 380 && msg.x <= 600 && msg.y >= 100 && msg.y <= 180)
			{
				jiemian = 1;
				return;
			}
			else if (msg.x >= 380 && msg.x <= 600 && msg.y >= 200 && msg.y <= 280)
			{
				exit(0);
				return;
			}
			else if (msg.x >= 300 && msg.x <= 600 && msg.y >= 300 && msg.y <= 380)
			{
				jiemian = 0;
				return;
			}
			break;
		default:
			break;
		}
	}
}
void scoreprint()
{
	settextcolor(mi);
	outtextxy(800, 40, s);
	if (sexy == 0)
		settextcolor(pink);
	else 
		settextcolor(blue);
	settextstyle(40, 0, L"Ink Free");
	_stprintf_s(s, _T("%d"), score);
	outtextxy(800,40, s);
}
void choosegender() 
{
	loadimage(&choose, L".\\image\\choose.jpg",900,600);
	putimage(0, 0, &choose);
	setbkmode(TRANSPARENT);
	settextstyle(80, 0, L"Ink Free", 0, 0, 1000, 0, 0, 0);
	settextcolor(RGB(0, 0, 0));
	outtextxy(90, 450, L"please choose your gender");
	while (1)
	{
		msg = GetMouseMsg();
		if (msg.x >= 180 && msg.x <= 400 && msg.y >= 70 && msg.y <= 430)
		{
			setlinecolor(RGB(0, 0, 0));
			rectangle(180,70,400,430);
		}
		else if (msg.x >= 500 && msg.x <= 720 && msg.y >= 70 && msg.y <= 430)
		{
			setlinecolor(RGB(0, 0, 0));
			rectangle(500,70,720,430);
		}
		else
		{
			setlinecolor(RGB(255,251,216));
			rectangle(180, 70, 400, 430);
			rectangle(500, 70, 720, 430);
		}
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (msg.x >= 180 && msg.x <= 400 && msg.y >= 70 && msg.y <= 430)
			{
				sexy = 0;
				mciSendString(L"open .\\musicc\\girl.mp3 alias scg", NULL, 0, NULL);
				return;
			}
			else if (msg.x >= 500 && msg.x <= 720 && msg.y >= 70 && msg.y <= 430)
			{
				sexy = 1;
				mciSendString(L"open .\\musicc\\boy.mp3 alias scg", NULL, 0, NULL);
				return;
			}
			break;
		default: 
			break;
		}
	}
}
void menujiemian()
{
	cleardevice();
	if (sexy)
		loadimage(&set, L".\\image\\set1.jpg", 900, 600);
	else
		loadimage(&set, L".\\image\\set0.jpg", 900, 600);
	putimage(0, 0, &set);
	while (1)
	{	
		settextstyle(60, 0, L"Ink Free");
		msg = GetMouseMsg();
		if (msg.x >= 500&& msg.x <= 680 && msg.y >=40 && msg.y <= 90)
		{
			if (sexy == 0)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(200, 70, L"music");
			outtextxy(500, 40, L"turn up");
		}
		else if (msg.x >= 500&& msg.x <= 710 && msg.y >= 110 && msg.y <= 160)
		{
			if (sexy == 0)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(200, 70, L"music");
			outtextxy(500, 100, L"turn down");
		}
		else if (msg.x >= 500 && msg.x <= 750 && msg.y >= 240 && msg.y <= 290)
		{
			if (sexy == 0)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(200, 270, L"mode");
			outtextxy(500, 240, L"classic mode");
		}
		else if (msg.x >= 500 && msg.x <= 750 && msg.y >= 300 && msg.y <= 350)
		{
			if (sexy == 0)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(200, 270, L"mode");
			outtextxy(500, 300, L"battle mode");
		}
		else if (msg.x >= 450 && msg.x <= 850 && msg.y >= 460 && msg.y <= 540)
		{
			if (sexy == 0)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(200, 470, L"instruction");
			settextstyle(30, 0, L"ink free");
			outtextxy(450, 460, L"← → ↑ ↓控制方向");
			outtextxy(450, 510, L"或用鼠标点击蛇头的上下左右来控制");
		}
		else if(msg.x >= 1 && msg.x <= 61 && msg.y >= 0 && msg.y <= 60)
		{
			if (sexy == 0)
				settextcolor(blue);
			else
				settextcolor(pink);
			outtextxy(1, 0, L"<<");
		}
		else
		{
			if (sexy == 0)
				settextcolor(pink);
			else
				settextcolor(blue);
			settextstyle(60, 0, L"Ink Free");
			outtextxy(200, 70, L"music");
			outtextxy(500, 40, L"turn up");
			outtextxy(500, 100, L"turn down");
			outtextxy(200, 270, L"mode");
			outtextxy(500, 240, L"classic mode");
			outtextxy(500, 300, L"battle mode");
			outtextxy(200, 470, L"instruction");
			outtextxy(1, 0, L"<<");
			settextstyle(30, 0, L"ink free");
			outtextxy(450, 460, L"← → ↑ ↓控制方向");
			outtextxy(450, 510, L"或用鼠标点击蛇头的上下左右来控制");	
		}
		switch (msg.uMsg)
		{
		case WM_LBUTTONDBLCLK:
			if (msg.x >= 500 && msg.x <= 680 && msg.y >= 40 && msg.y <= 90)
			{
				mciSendString(L"play scg repeat", NULL, 0, NULL);
			}
			else if (msg.x >= 500 && msg.x <= 710 && msg.y >= 110 && msg.y <= 160)
			{
				mciSendString(L"stop scg", NULL, 0, NULL);
			}
			else if (msg.x >= 500 && msg.x <= 750 && msg.y >= 240 && msg.y <= 290)
			{
				mode = 1;
			}
			else if (msg.x >= 500 && msg.x <= 750 && msg.y >= 300 && msg.y <= 350)
			{
				mode = 0;
				outtextxy(500, 380, L"*");
			}
			else if (msg.x >= 1 && msg.x <=61 && msg.y >= 0 && msg.y <= 60)
			{
				jiemian = 0;
				return;
			}
			break;
		default: break;
		}
	}
}

void Save()
{
	if (score > record)
	{
		ofstream out;
		out.open(".\\data\\data.txt", ios::out);
		out << score << endl;
		out.close();
	}
}

void Read()
{
	ifstream in;
	in.open(".\\data\\data.txt", ios::in);
	char s[10];
	in.getline(s, 10);
	record = atoi(s);
	in.close();
}
void ChangeDireByMouse(const int &x,const int &y)
{
	if (snake.dire == up || snake.dire == down)
	{
		if (snake.src[0].x > x)
		{
			snake.dire = left1;
		}
		else if(snake.src[0].x + 15 < x)
		{
			snake.dire = right1;
		}
		else
		{
			if (snake.dire == up)
			{
				if (snake.src[0].y >= y)
					speed -= 40;
				else 
					speed += 40;
			}
			else
			{
				if (snake.src[0].y <= y)
					speed -= 40;
				else 
					speed += 40;
			}
		}
	}
	else
	{
		if (snake.src[0].y > y)
		{
			snake.dire = up;
		}
		else if(snake.src[0].y+15<y)
		{
			snake.dire = down;
		}
		else
		{
			if (snake.dire == left1)
			{
				if (snake.src[0].x >= x)
					speed -= 40;
				else 
					speed += 40;
			}
			else
			{
				if (snake.src[0].x <= x)
					speed -= 40;
				else 
					speed += 40;
			}
		}
	}
}
DWORD proc(LPVOID lpThreadParameter)
{
	while (true)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN&& msg.x!=cake.food.x&& msg.y!=cake.food .y)
		{
			ChangeDireByMouse(msg.x, msg.y);
		}
	}
}