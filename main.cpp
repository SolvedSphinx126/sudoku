#include "grid.h"
#include "cell.h"

int main() {
    Grid puzzle;
    Cell *cell = puzzle.get(3, 7);
    puzzle.set_value(cell, 6);
    puzzle.print_grid();
    return 0;
}