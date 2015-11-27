#include "minesweeper.h"

ELEMENT** INIT_funct (
	int lin, 
	int col, 
	int mines, 
	COORD *poz, 
	bool *SET, 
	bool *NEW, 
	int *game_state, 
	int *helper)
{
	int i, j;
	ELEMENT **grila;
	grila = (ELEMENT**)malloc(lin*sizeof(ELEMENT*));
	*SET = 0;
	*NEW = 0;
	*game_state = 0;
	*helper = mines;
	poz->x = (col - 1) / 2;
	poz->y = (lin - 1) /2;

	for  (i = 0; i < lin; i++) {
		grila[i] = (ELEMENT *)malloc(col*sizeof(ELEMENT));
		for(j=0;j<col;j++) {
			grila[i][j].revealed = 0;
			grila[i][j].mine = 0;
			grila[i][j].marked = 0;
			grila[i][j].danger = 0;
		}
	}

	return grila;
}

