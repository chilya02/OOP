#include "../../include/cells/impassable_cell.hpp"

ImpassableCell::ImpassableCell(int y, int x):Cell(y, x){
  this->impassable = true;
}
ImpassableCell::ImpassableCell(const Cell& other):Cell(other){
  this->impassable = true;
  this->slow = false;
}

