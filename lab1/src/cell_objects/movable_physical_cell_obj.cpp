#include "../../include/cell_objects/movable_physical_cell_obj.hpp"

MovablePhysicalCellObject::MovablePhysicalCellObject(Cell* cell)
:MovableCellObject(cell){
  cell->busy = true;
}
bool MovablePhysicalCellObject::move(Cell* target){
  if (this->can_move(target)){
    this->cell->busy = false;
    MovableCellObject::move(target);
    target->busy = true;
    return true;
  }
  return false;
}