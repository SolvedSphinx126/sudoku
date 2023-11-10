#ifndef CELL_H
#define CELL_H

#include <cstdint>
#include <optional>
#include <vector>

class Cell {
public:
    uint8_t value;
    uint16_t hints;

    Cell();

    void set_hint(uint8_t val);

    void clear_hint(uint8_t val);

    std::vector<uint8_t> get_hints() const;
};

#endif
