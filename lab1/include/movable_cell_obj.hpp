#ifndef MOVABLE_CELL_OBJ_H
#define MOVABLE_CELL_OBJ_H

#include "cell_obj.hpp"

class MovableCellObject: public CellObject{
  public:
    MovableCellObject(Cell*);

  bool move_up();
  bool move_down();
  bool move_left();
  bool move_right();

  protected:
    virtual bool move(Cell* target);
};
#endif //MOVABLE_CELL_OBJ_H