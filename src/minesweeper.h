#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>

#define KEY_ESCAPE 27

typedef struct {
        bool revealed, mine, marked;
        int danger;
} ELEMENT;

typedef struct {
        int y;
        int x;
} COORD;

typedef struct {
        int hour;
        int min;
        int sec;
} TIMP;

void BREAK_funct (ELEMENT **grila, int lin, int col, COORD poz, int *game_state);

void marcare_multipla(ELEMENT **grila, int lin, int col, COORD poz, int *helper);

void lovire_multipla(ELEMENT **grila, int lin, int col, COORD poz, int *game_state);

void SHOW_funct(ELEMENT **grila, int lin, int col, COORD poz, int helper,
                time_t first_stamp, bool SET, TIMP *start);

void MINES_funct (ELEMENT **grila, int lin, int col, int mines, COORD poz, 
		time_t *first_stamp);

ELEMENT** INIT_funct (int lin, int col, int mines, COORD *poz, bool *SET, 
		bool *NEW, int *game_state, int *helper);

void SETTINGS_funct (int *lin, int *col, int *mines);

void MENU_funct (bool *EXIT, bool *NEW, int *lin, int *col, int *mines, 
		bool *SAVE, bool *LOAD);

#endif
