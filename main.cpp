#include "grid.h"
#include "cell.h"

int main() {
    Grid puzzle;
    puzzle.get(3,4)->hints = 16;
    puzzle.solveLoneSingles();
    puzzle.print_grid();
    return 0;
}
