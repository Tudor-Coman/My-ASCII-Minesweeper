#include "minesweeper.h"

int main ()
{
        initscr ();
        keypad(stdscr, TRUE);
	curs_set(0);
        start_color();
	set_escdelay(25);
	init_pair (1, COLOR_WHITE, COLOR_BLACK);
        init_pair (2, COLOR_RED, COLOR_BLACK);
	init_pair (3, COLOR_BLACK, COLOR_WHITE);
	init_pair (4, COLOR_BLACK, COLOR_RED);
	init_pair (5, COLOR_RED, COLOR_CYAN);
	timeout(500);
	srand(time(NULL));

	bool NEW = 0, EXIT = 0, SET = 0, SAVE = 0, LOAD = 0;
	int lin = 9, col = 9, mines = 10, INPUT, bricks, i, j, game_state, helper;
	int newlin = 9, newcol = 9, newmines = 10;
	time_t first_stamp;
	COORD poz;
	TIMP start={0,0,0};
	ELEMENT** grila;
	grila = INIT_funct (lin, col, mines, &poz, &SET, &NEW, &game_state, &helper);

	do {

		SHOW_funct (grila, lin, col, poz, helper, first_stamp, SET, &start); 
		INPUT = getch ();

		switch(INPUT) {
		case 27: MENU_funct (&EXIT, &NEW, &newlin, &newcol, &newmines, &SAVE, &LOAD); break;
		case KEY_RIGHT: if (poz.x < col - 1) 
					++poz.x; 
				else 
					poz.x = 0; 
		break;

		case KEY_LEFT: if(poz.x > 0)
					--poz.x; 
				else
					poz.x = col - 1;
		break;

		case KEY_UP: if (poz.y > 0)
					--poz.y;
				else
					poz.y = lin - 1;
		break;

		case KEY_DOWN: if (poz.y < lin - 1)
					++poz.y;
				else 
					poz.y = 0;
		break;

		case 'x': if(grila[poz.y][poz.x].revealed == 0)
				if (!SET) {
					SET=1;
					MINES_funct (grila, lin, col, mines, poz, &first_stamp);
					BREAK_funct (grila, lin, col,  poz, &game_state);
				} else
					BREAK_funct(grila, lin, col, poz, &game_state);
			else
				lovire_multipla(grila, lin, col, poz, &game_state);
		break;

		case 'm': if(grila[poz.y][poz.x].revealed == 0)	{
				if (grila[poz.y][poz.x].marked == 0) {
					grila[poz.y][poz.x].marked = 1;
					helper--;
				}
				else {
					grila[poz.y][poz.x].marked = 0;
					helper++;
				}
			}
			else
				marcare_multipla(grila, lin, col, poz, &helper);
				
		break;

		}

		if (SAVE == 1) {
			SAVE = 0;
			FILE *savefile;
			savefile = fopen("SAVE", "wb");
			first_stamp = time(NULL) - first_stamp;

			fwrite(&lin, sizeof(int), 1, savefile);
			fwrite(&col, sizeof(int), 1, savefile);
			fwrite(&helper, sizeof(int), 1, savefile);
			fwrite(&poz, sizeof(COORD), 1, savefile);
			fwrite(&first_stamp, sizeof(time_t), 1, savefile);
			fwrite(&start, sizeof(TIMP), 1, savefile);

			for(i=0;i<lin;i++)
				for(j=0;j<col;j++)
					fwrite(&grila[i][j], sizeof(ELEMENT), 1, savefile);
			
			fclose(savefile);
		}

		if (LOAD == 1) {

                        for(i=0;i<lin;i++)
                                free(grila[i]);
                        free(grila);

			LOAD = 0;
			SET=1;
			FILE *loadfile;
			loadfile = fopen ("SAVE", "rb");

			fread(&lin, sizeof(int), 1, loadfile);
                        fread(&col, sizeof(int), 1, loadfile);

			grila=(ELEMENT**)malloc(lin*sizeof(ELEMENT*));
			for(i=0;i<lin;i++)
				grila[i]=(ELEMENT*)malloc(col*sizeof(ELEMENT));

                        fread(&helper, sizeof(int), 1, loadfile);
                        fread(&poz, sizeof(COORD), 1, loadfile);
                        fread(&first_stamp, sizeof(time_t), 1, loadfile);
                        fread(&start, sizeof(TIMP), 1, loadfile);

                        for(i=0;i<lin;i++)
                                for(j=0;j<col;j++)
                                        fread(&grila[i][j], sizeof(ELEMENT), 1, loadfile);

                        fclose(loadfile);
			first_stamp = time(NULL) - first_stamp;
		}
		

		if (game_state == 2) {
			for(i=0;i<lin;i++)
				for(j=0;j<col;j++)
					if(grila[i][j].mine == 1)
						grila[i][j].revealed = 1;
			do
				SHOW_funct(grila, lin, col, poz, helper, first_stamp, SET, &start);
			while(getch()!=27);			
			
			while(!EXIT && !NEW)
				MENU_funct (&EXIT, &NEW, &newlin, &newcol, &newmines, &SAVE, &LOAD);		
		}
		
		bricks=0;
                for(i=0;i<lin;i++)
                        for(j=0;j<col;j++)
                                if(grila[i][j].revealed==0)
                                        bricks++;

                if(mines == bricks)
                        game_state = 1;

		if (game_state == 1) {

			do {
                                clear();
				refresh();
				color_set(2, NULL);
				mvprintw(10,20, "CONGRATULATIONS!!! YOU WON!");
				refresh();
			}
                        while(getch()!=27);

			while(!EXIT && !NEW)
                                MENU_funct (&EXIT, &NEW, &newlin, &newcol, &newmines, &SAVE, &LOAD);
                }


		if (NEW) {
			for(i=0;i<lin;i++)
				free(grila[i]);
			free(grila);
			lin=newlin;
                        col=newcol;
                        mines=newmines;

			grila=INIT_funct (lin, col, mines, &poz, &SET, &NEW, &game_state, &helper);
			continue;
		}
	}
	while(!EXIT);
	refresh ();
        endwin ();
        return 0;
}
