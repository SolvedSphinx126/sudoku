#ifndef GRID_H
#define GRID_H

#include <vector>
#include <optional>
#include <iostream>
#include "cell.h"

class Grid {
public:
    Cell vals[81];

    Grid();

    Cell* get(uint8_t x, uint8_t y);

    void solveLoneSingles();

    void solveHiddenSingles();

    void set_value(uint8_t x, uint8_t y, uint8_t val);

    void set_value(Cell* cell, uint8_t val);

    uint8_t get_col_id(Cell* cell);

    std::vector<Cell*> get_col(Cell* other);

    uint8_t get_row_id(Cell* cell);

    std::vector<Cell*> get_row(Cell* other);

    uint8_t get_box_id(Cell* cell);

    std::vector<Cell*> get_box(Cell* cell);

    void print_grid();
};

#endif
