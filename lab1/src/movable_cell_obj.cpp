#include "../include/movable_cell_obj.hpp"

MovableCellObject::MovableCellObject(Cell* cell):CellObject(cell){}

bool MovableCellObject::move(Cell* target){
  if (!target || target->is_impassable() || target->is_busy())
    return false;
  this->cell->busy = false;
  this->cell = target;
  target->busy = true;
  //this->status = target->is_slow() ? EntityStatus::Slowed : EntityStatus::Stay;
  return true;
}

bool MovableCellObject::move_down(){
  Cell* bottom = this->cell->get_bottom();
  return  this->move(bottom);
}

bool MovableCellObject::move_up(){
  Cell* top = this->cell->get_top();
  return this->move(top);
}

bool MovableCellObject::move_left(){
  Cell* left = this->cell->get_left();
  return this->move(left);
}

bool MovableCellObject::move_right(){
  Cell* right = this->cell->get_right();
  return this->move(right);
}