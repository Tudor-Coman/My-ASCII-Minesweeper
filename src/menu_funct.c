#include "minesweeper.h"

void MENU_funct (bool *EXIT, bool *NEW, int *lin, int *col, int *mines, bool *SAVE, bool *LOAD)
{
        bool MENU_EXIT = 0;
        int SELECTOR = 1;
        int  INPUT;

        COORD center;
        center.y=(LINES-6)/2;
        center.x=(COLS-10)/2;

        clear();

        do {
                color_set (1, NULL);
                mvaddstr (center.y+0, center.x, "   New Game");
                mvaddstr (center.y+1, center.x, "   Save Game");
                mvaddstr (center.y+2, center.x, "   Load Game");
                mvaddstr (center.y+3, center.x, "   Resume Game");
                mvaddstr (center.y+4, center.x, "   Settings");
                mvaddstr (center.y+5, center.x, "   Quit");
                color_set (2, NULL);

                switch (SELECTOR) {
                        case 1: mvaddstr (center.y+0, center.x, ">  New Game"); break;
                        case 2: mvaddstr (center.y+1, center.x, ">  Save Game"); break;
                        case 3: mvaddstr (center.y+2, center.x, ">  Load Game"); break;
                        case 4: mvaddstr (center.y+3, center.x, ">  Resume Game"); break;
                        case 5: mvaddstr (center.y+4, center.x, ">  Settings"); break;
                        case 6: mvaddstr (center.y+5, center.x, ">  Quit"); break;
                }

                INPUT = getch();

                switch (INPUT) {
                        case KEY_UP: if(SELECTOR != 1) SELECTOR--; break;
                        case KEY_DOWN: if (SELECTOR != 6) SELECTOR++; break;
                        case 27: MENU_EXIT=1; break;
                }

                if (INPUT == '\n' || INPUT == ' ') {
                        if (SELECTOR == 1) {
                                *NEW = 1;
                                break;
                        }
                        if (SELECTOR == 2) {
                                *SAVE = 1;
                                MENU_EXIT = 1;
                        }
                        if(SELECTOR == 3) {
                                *LOAD = 1;
                                MENU_EXIT = 1;
                        }
                        if(SELECTOR == 4)
                                MENU_EXIT = 1;
                        if (SELECTOR == 5)
                                SETTINGS_funct (lin, col, mines);
                        if (SELECTOR == 6) {
                                *EXIT = 1;
                                break;
                        }
                }
                refresh();
        }
        while (!MENU_EXIT);

        color_set (1, NULL);
        clear ();
}

