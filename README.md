## My ASCII Minesweeper
Simple Minesweeper game made with the curses.h library.

This is my first game ever made as the final project for my first year
C programming course.

Use the makefile to either compile it to the bin directory with 'make build'
or compile and run it with 'make run'

Use the arrow keys to navigate.
Press 'm' to mark a box or 'x' key to break the boxes.
Press ESC for settings and other goodies.

![](/pics/mine.png)

### Advanced Features
#### Multiple Mark
If the number of unknown boxes around a newly broken box is equal the number of mines indicated by the same box, pressing 'm' on the box marks all it's unknown neighbours because they are obviously mines.  

![](/pics/multiple_mark.png)

#### Multiple Hit
If the number of marked boxes around a newly broken box is equal the number of mines indicated by the same box, pressing 'x' on the box hits all the unmarked neighbours around because they are presumed not to be mines(they can be and doing so will cost you the game).

![](/pics/multiple_hit.png)
