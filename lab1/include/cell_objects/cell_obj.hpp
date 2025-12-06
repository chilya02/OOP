#ifndef CELL_OBJ_H
#define CELL_OBJ_H

#include "../cells/cell.hpp"

class CellObject{
  public:
    Cell* get_cell();
  protected:
    CellObject(Cell* cell);
    Cell* cell;

};

#endif //CELL_OBJ_H