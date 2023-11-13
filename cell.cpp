#include "cell.h"

Cell::Cell() {
    value = 0;
    hints = 0;
}

void Cell::set_hint(uint8_t val) {
    this->hints |= (1 << (val - 1));
}

void Cell::clear_hint(uint8_t val) {
    this->hints &= ~(1 << (val - 1));
}

std::vector<uint8_t> Cell::get_hints() {
    uint16_t cpy = this->hints;
    std::vector<uint8_t> ret;
    for (uint8_t i = 1; i <= 9; i++) {
        if (cpy % 2) {
            ret.push_back(i);
        }
        cpy >>= 1;
    }
    return ret;
}
