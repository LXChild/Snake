//#include "Snake.h"
///**********************************************JudgeRank***************************************/
//void JudgeRank(Snake snake)
//{
//	Rank *head,*p,*q,*rank;
//	FILE *fp;
//	long temp;
//	head = p;
//	p->next = q;
//	rank->score = snake.length - 3;
//	fopen_s(&fp, "Rank.dat", "ab+");
//	fseek(fp, 0, 2);
//	temp = ftell(fp);
//	fseek(fp, 0, 0);
//	while (temp > ftell(fp))
//	{
//		q = new Rank;
//		fread(q, sizeof(Rank), 1, fp);
//		if (rank->score > q->score)
//		{
//			system("cls");
//			GotoXY(30, 1);
//			cout << "Please input your name: ";
//			fflush(stdin);
//			cin >> rank->name;
//			p->next = rank;
//			rank->next = q;			
//		}
//		p = q;
//		q = q->next;		
//	}
//	fclose(fp);
//	SaveRank(head);
//}
///************************************************SaveRank*********************************/
//void SaveRank(Rank *head)
//{
//	int i;
//	Rank *p;
//	p = head;
//	while (p != NULL)
//		fwrite(head, sizeof(Rank), 1, fp);
//	}
//	GotoXY(30, 12);
//	cout << "Save Succsseful!!!" << endl;
//	fclose(fp);
//}
///********************************************DisplayRank************************************/
//void DisplayRank()
//{
//	int i = 1;
//	FILE *fp;
//	Rank *p;
//	fopen_s(&fp, "Rank.dat", "rb");
//	cout << "Ranking\n" << endl;
//	while (!(feof(fp)))
//	{
//		fread(p, sizeof(Rank), 1, fp);
//		cout << i << ".\t";
//		cout << p->name << "\t";
//		cout << p->score << endl;
//		i++;
//	}
//	fclose(fp);	
//	return;
//}