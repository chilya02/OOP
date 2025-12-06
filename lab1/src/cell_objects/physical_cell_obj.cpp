#include "../../include/cell_objects/physical_cell_obj.hpp"

PhysicalCellObject::PhysicalCellObject(Cell* cell)
:CellObject(cell){
  cell->busy = true;
}