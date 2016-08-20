#include "Snake.h"
#include <time.h>
#include <Windows.h>
#include <conio.h>
#define WALL cout<<"¡ö"
Snake snake;
static int Grade = 1;
/**************************************Main***************************************/
int main()
{
	Menu();
	return 0;
}
/*****************************************************Menu***************************************/
void Menu()
{
	int SelectNum;
	while (1)
	{
		system("cls");
		cout << "\n\n\n\t\t\tWelcome to play the Snake game\n" << endl;
		cout << "\t\t\t1.Start a new game" << endl;
		cout << "\t\t\t2.Continue the game" << endl;
		cout << "\t\t\t3.Display the Rank" << endl;
		cout << "\t\t\t4.Game setting" << endl;
		cout << "\t\t\t5.Game help" << endl;
		cout << "\t\t\t6.Exit" << endl;
		cout << "\n\t\t\tPlease input your choice: ";
		fflush(stdin);
		cin >> SelectNum;
		system("cls");
		switch (SelectNum)
		{
		case 1:
			Play(Grade,snake);
			break;
		case 2:
		//	snake.Continue();
			break;
		case 3:
	//		DisplayRank();
			break;
		case 4:
			Setting();
			break;
		case 5:
			Help();
			break;
		case 6:
			GotoXY(30, 6);
			cout << "Thanks for playing" << endl;
			_getch();
			exit(0);
		default:
			cout << "Please input the correct choice!!!\a" << endl;
			_getch();
		}
	}
}
/**************************************************GotoXY*************************************************/
void GotoXY(int x, int y)
{
	COORD Loc;
	Loc.X = x;
	Loc.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Loc);
}
/**************************************************DrowMap***************************************/
void DrowMap()
{
	int i;
	for (i = 0; i < 25; i++)
	{
		GotoXY(0, i);
		WALL;
		GotoXY(56, i);
		WALL;
		GotoXY(78, i);
		WALL;
	}
	for (i = 0; i < 78; i += 2)
	{
		GotoXY(i, 0);
		WALL;
		GotoXY(i, 24);
		WALL;
	}
}
/**********************************************GenerateFood**************************************/
void Food::Generate()
{
	srand((int)time(NULL));
	x = rand() % 53 + 2;
	y = rand() % 23 + 1;
	if (x % 2 != 0)
		x = x + 1;
	GotoXY(x, y);
	cout << "¡ï";
	exist = 1;
}
/******************************************CreateSnake************************************/
void Snake::CreateSnake()
{
	head = new Body;
	body = new Body;
	body->next = new Body;
	head->next = body;
	head->x = 10;
	head->y = 11;
	body->x = 10;
	body->y = 12;
	body->next->x = 10;
	body->next->y = 13;
	body->next->next = NULL;
	life = 1;
	DrowSnake();
}
/******************************************DrowSnake************************************/
void Snake::DrowSnake()
{
	temp = head;
	while (temp != NULL)
	{
		GotoXY(temp->x, temp->y);
		if (temp == head)
		{
			cout << "¡ò";
		}
		else
		{
			cout << "¡ñ";
		}
		temp = temp->next;
	}
	GotoXY(62, 10);
	cout << "Grade: " << Grade << endl;
	GotoXY(62, 13);
	cout << "Score: " << length - 3 << endl;
}
/******************************************SaveSnake**********************************************************/
//void Snake::SaveSnake()
//{
//	Snake S_snake;
//	S_snake = snake;
//	Body *p;
//	p = snake.head;
//	FILE *fp;
//	fopen_s(&fp, "snake.dat", "wb+");
//	while (p != NULL)
//	{
//		//fwrite(S_snake, sizeof(Snake), 1, fp);
//	}
//	fclose(fp);
//}
///*********************************************Continue***********************************************/
//void Snake::Continue()
//{
//	Body *p = NULL;
//	FILE *fp;
//	fopen_s(&fp, "snake.dat", "wb+");
//	while (p != NULL)
//	{
//		fread(p, sizeof(Body), 1, fp);
//	}
//}
/********************************************GameOver****************************************/
void GameOver(Snake snake)
{
	if (snake.life == 0)
	{
		system("cls");
		GotoXY(34, 13);
		cout << "You Lost!" << endl;
		GotoXY(30, 22);
		cout << "You Got: " << snake.length - 2 << "Scores" << endl;
	}
	else if (snake.length == 1000)
	{
		GotoXY(34, 13);
		cout << "You Win!!!" << endl;
		GotoXY(32, 14);
		cout << "Congratulations" << endl;
	}
	fflush(stdin);
	_getch();
}
/***********************************************setting***********************************/
void Setting()
{
	int SelectNum;
	
	cout << "Please choose the Grade:" << endl;
	cout << "\t1.easy" << endl;
	cout << "\t2.normal" << endl;
	cout << "\t3.hard" << endl;
	fflush(stdin);
	cin >> SelectNum;
	switch (SelectNum)
	{
	case 1:
		Grade = 1;
		break;
	case 2:
		Grade = 2;
		break;
	case 3:
		Grade = 3;
		break;
	default:
		cout << "Please input the correct choice!!!\a" << endl;
		_getch();
	}
}
/*************************************************Help************************************************/
void Help()
{
	char temp;
	FILE *fp;
	fopen_s(&fp,"ReadMe.txt", "r");
	while (!feof(fp))
	{
		temp = fgetc(fp);
		cout << temp;
	}
	fclose(fp);
	_getch();
}
