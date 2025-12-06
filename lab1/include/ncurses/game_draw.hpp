#ifndef GAME_DRAW_H
#define GAME_DRAW_H

#include "../common/game.hpp"
#include "config.hpp"
#include "abs_drawer.hpp"

class GameDraw final:public AbstractDrawer{
  public:
    GameDraw(Game* game);
    ~GameDraw();
    void draw() final;

  private:
    
    void draw_area();
    void draw_player();
    void draw_enemies();
    void draw_building();
    void draw_cell(Cell*);
    void draw_area_cell(Cell*);
    void print(int, int, const char*, int);
};

#endif