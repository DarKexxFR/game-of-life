#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

/* Constants */
#define WIDTH 80
#define HEIGHT 40
#define DELAY 100000 

/* Logic Functions */
void init_grid(int grid[HEIGHT][WIDTH]);
void update_grid(int grid[HEIGHT][WIDTH]);
int count_neighbors(int x, int y, int grid[HEIGHT][WIDTH]);

/* Display Functions */
void draw_grid(int grid[HEIGHT][WIDTH]);

#endif /* !GAME_OF_LIFE_H */
