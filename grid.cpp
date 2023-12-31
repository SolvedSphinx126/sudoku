#include "grid.h"

Grid::Grid() {
    for (Cell &cell : vals) {
        cell.hints = 0x01ff;
    }
}

Cell* Grid::get(uint8_t x, uint8_t y)
{
    return &vals[(x - 1) * 9 + (y - 1)];
}

void Grid::solveLoneSingles() {
    bool setAny = true;
    while (setAny) {
        setAny = false;
        for (Cell &cell : this->vals) {
            // BIT HACKING
            // If there is only 1 hint set
            if (((cell.hints & (cell.hints - 1)) == 0) && (cell.hints != 0)) {
                setAny = true;
                this->set_value(&cell, cell.get_hints()[0]);
            }
        }
    }
}

void Grid::solveHiddenSingles() {
    bool setAny = true;
    std::vector<std::vector<Cell*>> groups;
    while (setAny) {
        setAny = false;
        for (Cell &cell : this->vals) {
            groups.clear();
            // skip solved cells
            if (cell.hints != 0) {
                groups.push_back(this->get_box(&cell));
                groups.push_back(this->get_row(&cell));
                groups.push_back(this->get_col(&cell));
                for (std::vector<Cell*> &group : groups) {
                    uint16_t hintsInRestOfCells = 0;
                    for (Cell* otherCell : group) {
                        hintsInRestOfCells |= otherCell->hints;
                    }
                    // truthy if cell has a hidden single of val
                    if (uint16_t val = (~hintsInRestOfCells & cell.hints)) {
                        cell.hints = val;
                        this->set_value(&cell, cell.get_hints()[0]);
                        setAny = true;
                    }
                }
            }
        }
    }
}

void Grid::set_value(uint8_t x, uint8_t y, uint8_t val)
{
    Cell *cell = this->get(x, y);
    this->set_value(cell, val);
}

void Grid::set_value(Cell *cell, uint8_t val)
{
    cell->value = val;
    cell->hints = 0;
    for (Cell *affected : this->get_col(cell)) {
        affected->clear_hint(val);
    }
    for (Cell *affected : this->get_row(cell)) {
        affected->clear_hint(val);
    }
    for (Cell *affected : this->get_box(cell)) {
        affected->clear_hint(val);
    }
}

uint8_t Grid::get_col_id(Cell* cell)
{
    return ((cell - this->vals) % 9) + 1;
}

std::vector<Cell*> Grid::get_col(Cell* cell)
{
    std::vector<Cell*> result;
    for (Cell& other : vals) {
        if (get_col_id(&other) == get_col_id(cell) && cell != &other) {
            result.push_back(&other);
        }
    }
    return result;
}

uint8_t Grid::get_row_id(Cell *cell)
{
    return ((cell - this->vals) / 9) + 1;
}

std::vector<Cell*> Grid::get_row(Cell *cell)
{
    std::vector<Cell*> result;
    for (Cell& other : vals) {
        if (get_row_id(cell) == get_row_id(&other) && &other != cell) {
            result.push_back(&other);
        }
    }
    return result;
}

uint8_t Grid::get_box_id(Cell* cell)
{
    // Determine if the cell is in a row, column, or box
    uint8_t row = get_row_id(cell);
    uint8_t col = get_col_id(cell);
    uint8_t box_row = (row - 1) / 3;
    uint8_t box_col = (col - 1) / 3;

    return box_col + 3 * box_row + 1;
}

std::vector<Cell*> Grid::get_box(Cell *cell)
{
    std::vector<Cell*> result;
    for (Cell& other : vals) {
        if (get_box_id(cell) == get_box_id(&other) && &other != cell) {
            result.push_back(&other);
        }
    }
    return result;
}

void Grid::print_grid() {
    for (int row = 1; row <= 9; row++) {
        for (int col = 1; col <= 9; col++) {
            Cell* cell = this->get(row, col);
            if (cell->value == 0) {
                std::cout << " . ";
            } else {
                std::cout << " " << (int)cell->value << " ";
            }

            // Print vertical dividers
            if (col % 3 == 0 && col < 9) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;

        // Print horizontal dividers
        if (row % 3 == 0 && row < 9) {
            std::cout << "---------+---------+---------" << std::endl;
        }
    }
    std::cout << std::endl;
}
