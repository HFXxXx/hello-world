#include"stdafx.h"
#include"stdio.h"
#include"time.h"
#include"conio.h"
#include "stdlib.h"
#include"string.h"
#define MAX 100
using namespace std;
void input();
void sort();
void display();
void insert();
void del();
void average();
int now_no = 0;
struct student
{
	int no;
	char name[40];
	char sex[10];
	float score1;
	float score2;
	float score3;
	float sort;
	float ave;
	float sum;
};
struct student stu[MAX], *p;
int main()//主函数
{
	char as;
start: printf("\t\t\t欢迎使用学生成绩管理系统\n\n");
	//一下为功能选择模块
	do {
		printf("\n\t\t\t\t1.录入学员信息\n\t\t\t\t2.显示学员信息\n\t\t\t\t3.成绩排序信息\n\t\t\t\t4.添加学员信息\n\t\t\t\t5.删除学员信息\n\t\t\t\t6.退出\n");
		printf("\t\t\t\t选择功能选项:");
		as = _getch();
		switch (as)
		{
		case '1':system("cls");//清屏，其实我也不太懂system("cls")，现学。。。
			input();
			break;
		case '2':system("cls");
			display();
			break;
		case '3':system("cls");
			sort();
			break;
		case '4':system("cls");
			insert();
			break;
		case '5':system("cls");
			del();
			break;
		case '6':system("exit");
			exit(0);
		default:
			system("cls");
			goto start;
		}
	} while (1);
	//至此功能选择结束
}
void input()//原始数据录入模块
{
	int i = 0;
	char ch;
	do
	{
		printf("\t\t\t\t1.录入学员信息\n输入第%d个学员的信息\n", i + 1);
		printf("\n输入学生编号:");
		scanf_s("%d", &stu[i].no);
		fflush(stdin);
		printf("\n输入学员姓名:");
		fflush(stdin);
		gets_s(stu[i].name);
		printf("\n输入学员性别:");//这里有bug,姓名和性别会一块输出。。不会改。。
		fflush(stdin);
		gets_s(stu[i].sex);
		printf("\n输入学员数学成绩:");
		fflush(stdin);
		scanf_s("%f", &stu[i].score1);
		printf("\n输入学员英语成绩:");
		fflush(stdin);
		scanf_s("%f", &stu[i].score2);
		printf("\n输入学员编程成绩:");
		fflush(stdin);
		scanf_s("%f", &stu[i].score3);
		printf("\n\n");
		i++;
		now_no = i;
		printf("%d", now_no);
		printf("是否继续输入?(Y/N)");
		ch = _getch();
		system("cls");
	} while (ch != 'n');
	system("cls");
}
void sort()//排序数据函数
{
	struct student temp;
	int i, j;
	for (i = 1; i<now_no; i++)
	{
		for (j = 1; j <= now_no - i; j++)
		{
			if (stu[j - 1].ave<stu[j].ave)
			{
				temp = stu[j];
				stu[j] = stu[j - 1];
				stu[j - 1] = temp;
			}
		}
	}
}
void display()//显示数据函数
{
	int i;
	char as;
	float ave;
	do
	{
		printf("\t\t班级学员信息列表\n");
		printf("\t编号\t姓名\t性别\t成绩\t成绩\t成绩\t平均值\n");
		for (i = 0; i<now_no; i++)
		{
			stu[i].sum = stu[i].score1 + stu[i].score2 + stu[i].score3;
			stu[i].ave = stu[i].sum / 3;
			printf("\t%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].score1, stu[i].score2, stu[i].score3, stu[i].ave);
		}
		printf("\t\t按任意键返回主菜单.");
		as = _getch();
		goto exit;
	} while (as != 'n');
exit: system("cls");
}
void insert()//插入数据函数
{
	char ch;
	do
	{
		printf("\n\t\t输入新插入学员队信息\n");
		printf("\n输入学生编号:");
		scanf_s("%d", &stu[now_no].no);
		fflush(stdin);
		printf("\n输入学员姓名:");
		fflush(stdin);
		gets_s(stu[now_no].name);
		printf("\n输入学员性别:");
		fflush(stdin);
		gets_s(stu[now_no].sex);
		printf("\n输入学员成绩:");
		fflush(stdin);
		scanf_s("%f", &stu[now_no].score1);
		printf("\n输入学员成绩:");
		fflush(stdin);
		scanf_s("%f", &stu[now_no].score2);
		printf("\n输入学员成绩:");
		fflush(stdin);
		scanf_s("%f", &stu[now_no].score3);
		printf("\n\n");
		now_no = now_no + 1;
		sort();
		printf("是否继续输入?(Y/N)");
		ch = _getch();
		system("cls");
	} while (ch != 'n');
}
void del()//删除数据函数
{
	int inum, i, j;
	printf("输入要删除学员的编号:");
	fflush(stdin);
	scanf_s("%d", &inum);
	for (i = 0; i<now_no; i++)
	{
		if (stu[i].no == inum)
		{
			for (j = i; j<now_no; j++)
			{
				stu[i] = stu[i + 1];
			}
			now_no = now_no - 1;
		}
		break;
	}
	system("cls");
}

void average()
{
}
