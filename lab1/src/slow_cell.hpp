#ifndef SLOW_CELL_H
#define SLOW_CELL_H

#include "cell.hpp"

class SlowCell : public Cell{
  public:
    SlowCell();
    SlowCell(const Cell&);
    std::string view() override;
};

#endif //SLOW_CELL_H
