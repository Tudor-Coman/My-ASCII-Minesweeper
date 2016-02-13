#include "minesweeper.h"


void lovire_multipla(ELEMENT **grila, int lin, int col, COORD poz, int *game_state)
{
	int i,j, flagged = 0;
	COORD new_poz;
	for(i = -1; i < 2; i++)
		for(j = -1; j < 2; j++)
			if(0 <= poz.y + i && 
				poz.y + i < lin && 
				0 <= poz.x + j && 
				poz.x + j < col)
				if(grila[poz.y+i][poz.x+j].marked == 1)
					flagged++;

	if(flagged == grila[poz.y][poz.x].danger)
		for(i = -1; i < 2; i++)
			for(j = -1; j < 2; j++)
				if(0 <= poz.y + i && 
					poz.y + i < lin && 
					0 <= poz.x + j && 
					poz.x + j < col)
					if( grila[poz.y+i][poz.x+j].marked == 0 &&
						grila[poz.y+i][poz.x+j].revealed == 0) {
						new_poz.x = poz.x + j;
						new_poz.y = poz.y + i;
						BREAK_funct(grila, lin, col, new_poz, game_state);
					}
}

