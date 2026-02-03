#include "../../../../include/models/cell_objects/abstract/cell_obj.hpp"

CellObject::CellObject(Cell* cell):cell(cell), movable(false){}

Cell* CellObject::get_cell(){
  return this->cell;
}

bool CellObject::is_movable(){
  return this->movable;
}