#ifndef CELL_OBJ_H
#define CELL_OBJ_H

#include "cell.hpp"

class CellObject{
  public:
    CellObject(Cell* cell);
    Cell* get_cell();
  protected:
    Cell* cell;

};

#endif //CELL_OBJ_H