#include "../../../../include/models/cell_objects/abstract/physical_cell_obj.hpp"

PhysicalCellObject::PhysicalCellObject(Cell* cell)
:CellObject(cell){
  cell->busy = true;
}