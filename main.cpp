#include "grid.h"
#include "cell.h"

int main() {
    Grid puzzle;
    puzzle.set_value(3, 7, 6);
    puzzle.print_grid();
    return 0;
}