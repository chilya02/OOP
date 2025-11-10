#include "slow_cell.hpp"

SlowCell::SlowCell(int y, int x):Cell(y, x){
  this->impassable = false;
  this->slow = true;
}

SlowCell::SlowCell(const Cell& other):Cell(other){
  this->impassable = false;
  this->slow = true;
}

