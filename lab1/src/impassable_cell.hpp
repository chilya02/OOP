#ifndef IMPASSABLE_CELL_H
#define IMPASSABLE_CELL_H

#include "cell.hpp"

class ImpassableCell: public Cell {
  public:
    ImpassableCell();
    ImpassableCell(const Cell&);
    std::string view() override;
    
};
#endif //IMPASSABLE_CELL_H
