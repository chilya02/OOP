#ifndef PROGRESS_DRAW_H
#define PROGRESS_DRAW_H

#include "abstract/abs_game_drawer.hpp"
#include "config.hpp"

class ProgressDraw final : public AbstractGameDrawer{
  public:
    ProgressDraw(Game* game);
    ~ProgressDraw();
    void draw() final;
  private:
    void draw_enemies_HP();
    void draw_player_info();
    void draw_progress_bar(int, int, Entity*);
};

#endif

