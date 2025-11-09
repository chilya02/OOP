#include "impassable_cell.hpp"

ImpassableCell::ImpassableCell(){
  this->impassable = true;
}
ImpassableCell::ImpassableCell(const Cell& other): Cell::Cell(other){
  this->impassable = true;
  this->slow = false;
}

std::string ImpassableCell::view(){
  return std::string{"\x1B[4;41;37mMM\033[0m"};
}
