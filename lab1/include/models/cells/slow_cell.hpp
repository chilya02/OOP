#ifndef SLOW_CELL_H
#define SLOW_CELL_H

#include "cell.hpp"

class SlowCell : public Cell{
  public:
    SlowCell(int y, int x);
    SlowCell(const Cell&);
};

#endif //SLOW_CELL_H
