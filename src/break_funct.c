#include "minesweeper.h"

void BREAK_funct (ELEMENT **grila, int lin, int col, COORD poz, int *game_state)
{
        int i,j;
        COORD new_poz;

        if(grila[poz.y][poz.x].mine != 1) {
                grila[poz.y][poz.x].revealed = 1;

                if(grila[poz.y][poz.x].danger == 0)

                        for(i=-1;i<2;i++)
                                for(j=-1;j<2;j++)

                                        if( 0 <= poz.y+i && poz.y+i < lin && 0 <= poz.x+j && poz.x+j < col )

                                                if( grila[poz.y+i][poz.x+j].revealed == 0 &&
                                                        grila[poz.y+i][poz.x+j].marked == 0) {

                                                        grila[poz.y+i][poz.x+j].revealed = 1;
                                                        new_poz.x = poz.x + j;
                                                        new_poz.y = poz.y + i;
                                                        BREAK_funct (grila, lin, col, new_poz, NULL);
                                                }

        }
        else
                *game_state = 2;
}

