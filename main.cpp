#include "grid.h"
#include "cell.h"

int main() {
    Grid puzzle;

    uint8_t vals[9][9] = {
        {0, 0, 0,   0, 1, 4,   0, 0, 3},
        {0, 0, 3,   2, 0, 0,   0, 1, 0},
        {0, 2, 1,   9, 8, 0,   4, 0, 0},
        {2, 8, 0,   0, 9, 5,   0, 0, 4},
        {0, 0, 0,   4, 2, 8,   0, 0, 0},
        {9, 0, 0,   6, 7, 0,   0, 2, 5},
        {0, 0, 5,   0, 4, 6,   7, 8, 0},
        {0, 4, 0,   0, 0, 2,   6, 0, 0},
        {6, 0, 0,   8, 3, 0,   0, 0, 0},
    };

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (vals[row][col] != 0) {
                puzzle.set_value(row + 1, col + 1, vals[row][col]);
            }
        }
    }

    puzzle.print_grid();
    puzzle.solveHiddenSingles();
    puzzle.print_grid();
    return 0;
}
