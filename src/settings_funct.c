#include "minesweeper.h"

void SETTINGS_funct (int *lin, int *col, int *mines)
{
        bool SETTINGS_EXIT = 0;
        int SELECTOR = 1;
        int  INPUT;
        clear();

        COORD center;
        center.y=(LINES-6)/2;
        center.x=(COLS-10)/2;

        do {

                color_set (1, NULL);
                mvprintw (center.y+0, center.x, "   Lines   <  %2d  >", *lin);
                mvprintw (center.y+1, center.x, "   Columns <  %2d  >", *col);
                mvprintw (center.y+2, center.x, "   Mines   <  %2d  >", *mines);
                mvprintw (center.y+4, center.x, "   Exit Settings");
                color_set (2, NULL);

                switch (SELECTOR) {
                        case 1: mvprintw (center.y+0, center.x, 
							">  Lines   <  %2d  >", *lin); break;
                        case 2: mvprintw (center.y+1, center.x, 
							">  Columns <  %2d  >", *col); break;
                        case 3: mvprintw (center.y+2, center.x, 
								">  Mines   <  %2d  >", *mines); break;
                        case 4: mvprintw (center.y+4, center.x, 
							">  Exit Settings"); break;
                }

                INPUT = getch();

                switch (INPUT) {
                        case KEY_UP: if(SELECTOR != 1) SELECTOR--; break;
                        case KEY_DOWN: if (SELECTOR != 4) SELECTOR++; break;
                        case 27: SETTINGS_EXIT = 1; break;
                        case '\n': if (SELECTOR == 4); SETTINGS_EXIT=1; break;
                        case ' ': if (SELECTOR ==4 ); SETTINGS_EXIT=1; break;
                }

                if (INPUT == KEY_RIGHT)
                        switch (SELECTOR) {
                        case 1: if (*lin != 30) (*lin)++; break;
                        case 2: if (*col != 30)  (*col)++; break;
                        case 3: if (*mines != (*lin)*(*col)) (*mines)++; break;
                }

                if (INPUT == KEY_LEFT)
                        switch (SELECTOR) {
                        case 1: if (*lin != 1) (*lin)--; break;
                        case 2: if (*col != 1)  (*col)--; break;
                        case 3: if (*mines != 1) (*mines)--; break;
                }

                refresh();
        }
        while(!SETTINGS_EXIT);

        color_set (1, NULL);
        clear ();
}

