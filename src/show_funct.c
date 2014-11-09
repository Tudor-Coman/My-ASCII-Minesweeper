#include "minesweeper.h"

void SHOW_funct(ELEMENT **grila,
                int lin,
                int col,
                COORD poz,
                int helper,
                time_t first_stamp,
                bool SET,
                TIMP *start)

{
        int i,j;
        clear();
        refresh();
        WINDOW *local_win;
        COORD center;
        center.y = (LINES - 2 * lin + 1) / 2;
        center.x = (COLS - 4 * col + 1) / 2;

        time_t now;
        now = time(NULL);
        struct tm *prezent;
        prezent = localtime(&now);


        local_win = newwin(2*lin+1, 4*col+1, center.y+5, center.x);
        box (local_win, 0, 0);

        mvprintw (center.y+0, center.x , "Time and date: %s", asctime(prezent));

        if (!SET)
                mvprintw (center.y+1, center.x , "Time since first break: %d", 0);
        else
                mvprintw (center.y+1, center.x , "Time since first break: %d", now-first_stamp);

        mvprintw (center.y+2, center.x , "Presumed mines left: %d", helper);

        for(i=0;i<lin-1;i++)
                for(j=0;j<4*col-1;j++)
                        mvwprintw(local_win, 2+2*i, 1+j, "-");

        for(i=0;i<2*lin-1;i++)
                for(j=0;j<col-1;j++)
                        mvwprintw(local_win, 1+i, 4+4*j, "|");

        for(i=0;i<lin;i++)
                for(j=0;j<col;j++) {

                        if(poz.y==i && poz.x==j)
                                wcolor_set(local_win, 5, NULL);
                        else
                                wcolor_set(local_win, 1, NULL);

                        if (grila[i][j].revealed==1 && grila[i][j].mine==0 && grila[i][j].danger!=0)
                                mvwprintw (local_win, 1+2*i, 2+4*j, "%d", grila[i][j].danger);

                        if (grila[i][j].revealed==1 && grila[i][j].mine==0 && grila[i][j].danger==0)
                                mvwprintw (local_win, 1+2*i, 2+4*j, " ");

                        if(grila[i][j].revealed==1 && grila[i][j].mine==1) {
                                wcolor_set(local_win, 4, NULL);
                                mvwprintw (local_win, 1+2*i, 2+4*j, "*");
                        }

                        if (grila[i][j].revealed==0 && grila[i][j].marked==0) {

                                        if(poz.y==i && poz.x==j)
                                                wcolor_set(local_win, 5, NULL);
                                        else
                                                wcolor_set(local_win, 3, NULL);

                                        mvwprintw (local_win, 1+2*i, 2+4*j, "?");

                        }
                        if (grila[i][j].revealed==0 && grila[i][j].marked==1) {

                                        if(poz.y==i && poz.x==j)
                                                wcolor_set(local_win, 5, NULL);
                                        else
                                                wcolor_set(local_win, 3, NULL);

                                        mvwprintw (local_win, 1+2*i, 2+4*j, "M");
                        }
                }
        wrefresh (local_win);
        refresh();
        delwin(local_win);
}

