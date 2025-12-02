#include "../include/cell_obj.hpp"

CellObject::CellObject(Cell* cell):cell(cell){
  cell->busy = true;
}

Cell* CellObject::get_cell(){
  return this->cell;
}
