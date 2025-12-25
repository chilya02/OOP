#ifndef HAND_DRAW_H
#define HAND_DRAW_H 

#include "abs_drawer.hpp"

class HandDraw: public AbstractDrawer{
  public:
    HandDraw(Game* game);
    ~HandDraw();
    void draw() final;
};

#endif // HAND_DRAW_H