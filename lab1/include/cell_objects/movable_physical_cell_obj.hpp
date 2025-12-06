#ifndef MOVABLE_PHYSICAL_CELL_OBJ_H
#define MOVABLE_PHYSICAL_CELL_OBJ_H

#include "movable_cell_obj.hpp"
#include "physical_cell_obj.hpp"

class MovablePhysicalCellObject : public MovableCellObject{
public:
  MovablePhysicalCellObject(Cell* cell);
  bool move(Cell* cell) override;
};
#endif
