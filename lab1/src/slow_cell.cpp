#include "slow_cell.hpp"

SlowCell::SlowCell(){
  this->impassable = false;
  this->slow = true;
}

SlowCell::SlowCell(const Cell& other): Cell::Cell(other){
  this->impassable = false;
  this->slow = true;
}

std::string SlowCell::view(){
  return std::string{"\033[3;104;30m~~\033[0m"}; 
}
