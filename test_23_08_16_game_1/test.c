#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"


void menu()
{
	printf("******************************************\n");
	printf("***** 1. ������               0. Exit*****\n");
	printf("******************************************\n");
}

//��Ϸ�㷨ʵ��
void game()
{
	//����������������Ϣ
	char board[ROW][COL];
	char reg;
	//��ʼ�����̡�������Ԫ�ظ�Ϊ�ո��ַ�
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//�������
		PlayerTurn(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		system("cls");
		//�ж���Ӯ
		//����'*'--���Ӯ
		//����'#'--AIӮ
		//����'Q'--ƽ��
		//����'C'--����
		reg = Is_Win(board,ROW,COL);
		if (reg != 'C')
		{
			break;
		}
		//��������
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
		printf("���Ӯ\n");
	}
	else if (reg == '#')
	{
		printf("AIӮ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}


//���Ժ���
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}

//������
int main()
{
	test();
	return 0;
}