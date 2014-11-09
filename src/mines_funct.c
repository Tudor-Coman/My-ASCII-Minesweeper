#include "minesweeper.h"

void MINES_funct (ELEMENT **grila, int lin, int col, int mines, COORD poz, time_t *first_stamp)
{
        int i, j, try=0;
        int key, aleator;
        *first_stamp=time(NULL);
        aleator=rand();
        while(try<mines) {

                srand(aleator=aleator*3);
                key=rand()%(lin*col);

                if (grila[key/lin][key%col].mine==0 && poz.x!=key%col && poz.y!=key%lin) {
                        grila[key/lin][key%col].mine=1;

                        for(i=-1;i<2;i++)
                                for(j=-1;j<2;j++)

                                        if(0<=key/lin+i && key/lin+i<lin && 0<=key%col+j && key%col+j<col)
                                                grila[key/lin+i][key%col+j].danger++;
                                                        try++;
                }
        }
}

