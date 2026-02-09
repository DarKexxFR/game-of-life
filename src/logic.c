#include "logic.h"

void init_grid(int grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2; // Remplit aléatoirement au début
        }
    }
}

int count_neighbors(int x, int y, int grid[HEIGHT][WIDTH]) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int ni = x + i;
            int nj = y + j;
            if (ni >= 0 && ni < HEIGHT && nj >= 0 && nj < WIDTH)
                count += grid[ni][nj];
        }
    }
    return count;
}

void update_grid(int grid[HEIGHT][WIDTH]) {
    int next[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = count_neighbors(i, j, grid);
            if (grid[i][j] == 1)
                next[i][j] = (neighbors == 2 || neighbors == 3);
            else
                next[i][j] = (neighbors == 3);
        }
    }
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            grid[i][j] = next[i][j];
}
