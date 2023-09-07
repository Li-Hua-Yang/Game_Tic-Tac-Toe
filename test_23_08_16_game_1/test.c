#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"


void menu()
{
	printf("******************************************\n");
	printf("***** 1. 三子棋               0. Exit*****\n");
	printf("******************************************\n");
}

//游戏算法实现
void game()
{
	//创建数组存放棋盘信息
	char board[ROW][COL];
	char reg;
	//初始化棋盘——所有元素改为空格字符
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//玩家下棋
		PlayerTurn(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		system("cls");
		//判断输赢
		//返回'*'--玩家赢
		//返回'#'--AI赢
		//返回'Q'--平局
		//返回'C'--继续
		reg = Is_Win(board,ROW,COL);
		if (reg != 'C')
		{
			break;
		}
		//电脑下棋
		AITurn(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		reg = Is_Win(board, ROW, COL);
		if (reg != 'C')
		{
			break;
		}
	}
	if (reg == '*')
	{
		printf("玩家赢\n");
	}
	else if (reg == '#')
	{
		printf("AI赢\n");
	}
	else
	{
		printf("平局\n");
	}
}


//测试函数
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}

//主函数
int main()
{
	test();
	return 0;
}