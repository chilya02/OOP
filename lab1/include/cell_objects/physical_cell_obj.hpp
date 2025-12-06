#ifndef PHYSICAL_CELL_OBJ_H
#define PHYSICAL_CELL_OBJ_H

#include "cell_obj.hpp"
class PhysicalCellObject : public CellObject{
  public:
    PhysicalCellObject(Cell* cell);
};

#endif