#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3	//��������
#define COL 3	//��������


//��������
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerTurn(char board[ROW][COL], int row, int col);
void AITurn(char board[ROW][COL], int row, int col);
char Is_Win(char board[ROW][COL], int row, int col);

#endif // !__GAME_H__
