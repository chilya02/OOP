#ifndef CELL_OBJ_H
#define CELL_OBJ_H

#include "../../cells/cell.hpp"

class CellObject{
  public:
    Cell* get_cell();
    bool is_movable();
  protected:
    CellObject(Cell* cell);
    Cell* cell;
    bool movable;
};

#endif //CELL_OBJ_H