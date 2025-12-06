#ifndef IMPASSABLE_CELL_H
#define IMPASSABLE_CELL_H

#include "cell.hpp"

class ImpassableCell: public Cell {
  public:
    ImpassableCell(int y, int x);
    ImpassableCell(const Cell&);
};
#endif //IMPASSABLE_CELL_H
