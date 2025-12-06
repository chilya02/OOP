#ifndef PROGRESS_DRAW_H
#define PROGRESS_DRAW_H

#include "abs_drawer.hpp"

#include "../game.hpp"

class ProgressDraw final : public AbstractDrawer{
  ProgressDraw(Game* game);
  ~ProgressDraw();
  void create_window();
  void draw();
};

#endif

