#include "logic.h"
#include <time.h>

void draw_grid(int grid[HEIGHT][WIDTH]) {
    clear();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j]) mvaddch(i, j, 'O');
        }
    }
    refresh();
}

int main() {
    int grid[HEIGHT][WIDTH];
    srand(time(NULL));

    initscr();
    noecho(); 
    curs_set(0); 
    timeout(100); 

    init_grid(grid);

    while (getch() == ERR) {
        draw_grid(grid);
        update_grid(grid);
        sleep(100000); 
    }

    endwin(); 
    return 0;
}
