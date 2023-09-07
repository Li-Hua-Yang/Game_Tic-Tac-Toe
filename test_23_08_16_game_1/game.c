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
	for (i = 0; i < row + 1; i++)	//��������
	{	
		if (i == 0)	//��һ�д�ӡ������
		{
			for (j = 0; j < col + 1; j++)
			{
				if (j < col)	//�������һ�У������'|'
				{
					printf(" %d |", j);
				}
				else	//�����һ�У����滻��
				{
					printf(" %d \n", j);
				}
			}
			for (j = 0; j < col + 1; j++)	//��ӡһ�б߿�
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
			for (j = 0; j < col + 1; j++)	//��ӡ��������
			{
				if (j == 0)
				{
					printf(" %d |", i);
				}
				else
				{
					if (j < col)	//�������һ�У������'|'
					{
						printf(" %c |", board[i - 1][j - 1]);
					}
					else	//�����һ�У����滻��
					{
						printf(" %c \n", board[i - 1][j - 1]);
					}
				}
			}
			if (i < row)	//�������һ�У���ӡһ�б߿�
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
	printf("������壺\n");
	while (1)
	{
		printf("��������У�>");
		scanf("%d", &i);
		printf("��������У�>");
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
				printf("�ô��������ӣ�����������\n");
			}
		}
		else
		{
			printf("�������д������������루1/2/3��\n");
		}
	}
}

void AITurn(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("AI���壺\n");
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
	int z = 2; //����ɨ���ά����Ԫ�صķ�Χ�������壺z = 2�������壺z = 4
	for (i = 0; i < row; i++) //���ͬһ���Ƿ�����������ͬ��Ԫ��
	{
		for (j = 0; j < col - z; j++)
		{
			if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
		}
	}
	for (j = 0; j < col; j++) //���ͬһ���Ƿ�����������ͬ��Ԫ��
	{
		for (i = 0; i < row - z; i++)
		{
			if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row - z; i++) //������Խ���ƽ�з����Ƿ�����������ͬ��Ԫ��
	{
		for (j = 0; j < col - z; j++)
		{
			if ((board[i][j] == board[i + 1][j + 1]) && (board[i][j] == board[i + 2][j + 2]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
		}
	}
	for (j = z; j < col; j++) //��⸱�Խ���ƽ�з����Ƿ�����������ͬ��Ԫ��
	{
		for (i = 0; i < row - z; i++)
		{
			if ((board[i][j] == board[i + 1][j - 1]) && (board[i][j] == board[i + 2][j - 2]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row; i++) //����Ƿ���������
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'C';	//δ����������
			}
		}
	}
	return 'Q';	//����������ƽ��
}