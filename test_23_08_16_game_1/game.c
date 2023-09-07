#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row + 1; i++)	//控制行数
	{	
		if (i == 0)	//第一行打印列坐标
		{
			for (j = 0; j < col + 1; j++)
			{
				if (j < col)	//不是最后一列，后面加'|'
				{
					printf(" %d |", j);
				}
				else	//是最后一列，后面换行
				{
					printf(" %d \n", j);
				}
			}
			for (j = 0; j < col + 1; j++)	//打印一行边框
			{
				if (j < col)
				{
					printf("---|");
				}
				else
				{
					printf("---\n");
				}
			}
		}
		else
		{
			for (j = 0; j < col + 1; j++)	//打印三字棋行
			{
				if (j == 0)
				{
					printf(" %d |", i);
				}
				else
				{
					if (j < col)	//不是最后一列，后面加'|'
					{
						printf(" %c |", board[i - 1][j - 1]);
					}
					else	//是最后一列，后面换行
					{
						printf(" %c \n", board[i - 1][j - 1]);
					}
				}
			}
			if (i < row)	//不是最后一行，打印一行边框
			{
				for (j = 0; j < col + 1; j++)
				{
					if (j < col)
					{
						printf("---|");
					}
					else
					{
						printf("---\n");
					}
				}
			}
		}
	}
}

void PlayerTurn(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("玩家下棋：\n");
	while (1)
	{
		printf("玩家输入行：>");
		scanf("%d", &i);
		printf("玩家输入列：>");
		scanf("%d", &j);
		if ((i >= 1 && i <= row) && (j >= 1 && j <= col))
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("该处已有棋子，请重新输入\n");
			}
		}
		else
		{
			printf("输入行列错误，请重新输入（1/2/3）\n");
		}
	}
}

void AITurn(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("AI下棋：\n");
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}

char Is_Win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int z = 2; //控制扫描二维数组元素的范围，三子棋：z = 2；五子棋：z = 4
	for (i = 0; i < row; i++) //检测同一行是否有连续且相同的元素
	{
		for (j = 0; j < col - z; j++)
		{
			if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
		}
	}
	for (j = 0; j < col; j++) //检测同一列是否有连续且相同的元素
	{
		for (i = 0; i < row - z; i++)
		{
			if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row - z; i++) //检测主对角线平行方向是否有连续且相同的元素
	{
		for (j = 0; j < col - z; j++)
		{
			if ((board[i][j] == board[i + 1][j + 1]) && (board[i][j] == board[i + 2][j + 2]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
		}
	}
	for (j = z; j < col; j++) //检测副对角线平行方向是否有连续且相同的元素
	{
		for (i = 0; i < row - z; i++)
		{
			if ((board[i][j] == board[i + 1][j - 1]) && (board[i][j] == board[i + 2][j - 2]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row; i++) //检测是否下满棋盘
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'C';	//未下满，继续
			}
		}
	}
	return 'Q';	//下满，返回平局
}