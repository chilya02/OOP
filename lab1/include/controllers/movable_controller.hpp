#ifndef MOVABLE_CONTROLLER_H
#define MOVABLE_CONTROLLER_H

#include "../cell_objects/movable_cell_obj.hpp"
#include "../common/game_commands.hpp"

class MovableController{
  protected:
    MovableController(MovableCellObject* obj);
    bool move_obj(Command command);
  private:
    MovableCellObject* obj;

};
#endif // MOVABLE_CONTROLLER_H