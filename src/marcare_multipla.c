#include "minesweeper.h"

void marcare_multipla(
	ELEMENT **grila, 
	int lin, 
	int col, 
	COORD poz, 
	int *helper
)
{
	int i, j, unseen = 0;

	for(i = -1; i < 2; i++)
		for(j = -1; j < 2; j++)

			if(0 <= poz.y + i && 
				poz.y + i < lin && 
				0 <= poz.x + j && 
				poz.x + j < col)

				if(grila[poz.y+i][poz.x+j].revealed == 0)
					unseen++;

				if(unseen == grila[poz.y][poz.x].danger)

					for(i = -1; i < 2; i++)
						for(j = -1; j < 2; j++)

							if( 0 <= poz.y + i && 
								poz.y + i < lin && 
								0 <= poz.x + j && 
								poz.x + j < col)
								if( grila[poz.y+i][poz.x+j].revealed == 0 && 
									grila[poz.y+i][poz.x+j].marked == 0) {
									grila[poz.y+i][poz.x+j].marked = 1;
									(*helper)--;
								}
}
