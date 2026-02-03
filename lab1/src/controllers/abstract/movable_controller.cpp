#include "../../../include/controllers/abstract/movable_controller.hpp"

MovableController::MovableController(MovableCellObject* obj)
:obj(obj){}

bool MovableController::move_obj(Command command){
  switch (command){
    case Command::Up:
      return this->obj->move_up();
    case Command::Down:
      return this->obj->move_down();
    case Command::Right:
      return this->obj->move_right();
    case Command::Left:
      return this->obj->move_left();
    default:
      return false;
  }
}

Cell* MovableController::get_cell(){
  return this->obj->get_cell();
}