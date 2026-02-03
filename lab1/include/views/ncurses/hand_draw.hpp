#ifndef HAND_DRAW_H
#define HAND_DRAW_H 

#include "abstract/abs_drawer.hpp"

class HandDraw: public AbstractDrawer{
  public:
    HandDraw(Game* game);
    ~HandDraw();
    void draw() final;
  private:
    void draw_card(int, SpellCardInterface* card);
};

#endif // HAND_DRAW_H