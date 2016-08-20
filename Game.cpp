#include "Snake.h"
#include <Windows.h>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
/************************************************Play**************************************/
void Play(int Grade,Snake snake)
{
	DrowMap();
	snake.CreateSnake();
	while (1)
	{
		snake.Life();
		if (snake.life == 0)
		{
			break;
		}			
		if (snake.food.exist == 0)
		{
			snake.food.Generate();
		}
		if (GetAsyncKeyState(VK_UP) && snake.Direction != DOWN)
		{
			snake.Direction = UP;
		}
		if (GetAsyncKeyState(VK_DOWN) && snake.Direction != UP)
		{
			snake.Direction = DOWN;
		}
		if (GetAsyncKeyState(VK_LEFT) && snake.Direction != RIGHT)
		{
			snake.Direction = LEFT;
		}
		if (GetAsyncKeyState(VK_RIGHT) && snake.Direction != LEFT)
		{
			snake.Direction = RIGHT;
		}
		snake.Game();
		snake.DrowSnake();
		Sleep(500 - Grade * 150);
	}
	snake.food.exist = 0;
	snake.length = 3;
	snake.Direction = UP;
	GameOver(snake);
//	JudgeRank(snake);
}
/*******************************************Game****************************************/
void Snake::Game()
{
	if (Direction == UP)
	{
		if (head->x == food.x&&head->y == food.y + 1)
		{
			Grow();
		}
		else
		{
			MoveUp();
		}
	}
	if (Direction == DOWN)
	{
		if (head->x == food.x&&head->y == food.y - 1)
		{
			Grow();
		}
		else
		{
			MoveDown();
		}
	}
	if (Direction == LEFT)
	{
		if (head->x == food.x + 2&&head->y == food.y)
		{
			Grow();
		}
		else
		{
			MoveLeft();
		}
	}
	if (Direction == RIGHT)
	{
		if (head->x == food.x - 2&&head->y == food.y)
		{
			Grow();
		}
		else
		{
			MoveRight();
		}
	}
}
/*********************************************Move**********************************/
void Snake::MoveUp()
{
	newhead = new Body;
	newhead->x = head->x;
	newhead->y = head->y - 1;
	newhead->next = head;
	head = newhead;
	temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	GotoXY(temp->next->x, temp->next->y);
	cout << "  ";
	delete(temp->next);
	temp->next = NULL;
}
void Snake::MoveDown()
{
	newhead = new Body;
	newhead->x = head->x;
	newhead->y = head->y + 1;
	newhead->next = head;
	head = newhead;
	temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	GotoXY(temp->next->x, temp->next->y);
	cout << "  ";
	delete(temp->next);
	temp->next = NULL;
}
void Snake::MoveLeft()
{
	newhead = new Body;
	newhead->x = head->x - 2;
	newhead->y = head->y;
	newhead->next = head;
	head = newhead;
	temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	GotoXY(temp->next->x, temp->next->y);
	cout << "  ";
	delete(temp->next);
	temp->next = NULL;
}
void Snake::MoveRight()
{
	newhead = new Body;
	newhead->x = head->x + 2;
	newhead->y = head->y;
	newhead->next = head;
	head = newhead;
	temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	GotoXY(temp->next->x, temp->next->y);
	cout << "  ";
	delete(temp->next);
	temp->next = NULL;
}
/****************************************Grow****************************************/
void Snake::Grow()
{
	newhead = new Body;
	newhead->x = food.x;
	newhead->y = food.y;
	newhead->next = head;
	head = newhead;
	food.exist = 0;
	length += 1;
}
/****************************************Life**************************************/
void Snake::Life()
{
	Body *temp;
	temp = head->next;
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 24)
	{
		life = 0;		
	}
	while (!(temp->x == head->x&&temp->y == head->y))
	{
		if (temp->next == NULL)
		{
			return;
		}
		temp = temp->next;
	}
	life = 0;	
}
/*********************************************initialize*****************************************************/
Food::Food()
{
	exist = 0;
}
Snake::Snake()
{
	life = 1;
	length = 3;
	Direction = UP;
}
