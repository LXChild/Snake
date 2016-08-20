#pragma once
#include <iostream>
using namespace std;
typedef struct body
{
	int x;
	int y;
	struct body *next;
}Body;
//typedef struct rank
//{
//	
//	int score;
//	string name;
//	struct rank *next;
//}Rank;
class Snake;
class Food
{
private:
	friend Snake;
	int x;
	int y;
public:
	bool exist;
	void Generate();
	Food();
};
class Snake
{
private:	
	Body *head,*body;
	Body *newhead,*temp;	
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Grow();	
public:
	Food food;
	void Life();
	void DrowSnake();	
	int length;	
	int Direction;
	bool life;
	void CreateSnake();
	void Game();
	void SaveSnake();
	//void Continue();
	Snake();
};
void GotoXY(int x, int y);
void Menu();
void Play(int Grade,Snake snake);
void DrowMap();
void GameOver(Snake sanke);
void Help();
void Setting();
//void JudgeRank(Snake snake);
//void SaveRank(Rank *head);
//void DisplayRank();

