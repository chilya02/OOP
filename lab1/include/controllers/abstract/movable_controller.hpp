#ifndef MOVABLE_CONTROLLER_H
#define MOVABLE_CONTROLLER_H

#include "../../models/cell_objects/abstract/movable_cell_obj.hpp"
#include "../../common/game_commands.hpp"

class MovableController{
  public:
    Cell* get_cell();
  protected:
    MovableController(MovableCellObject* obj);
    bool move_obj(Command command);
  private:
    MovableCellObject* obj;
};

#endif // MOVABLE_CONTROLLER_H