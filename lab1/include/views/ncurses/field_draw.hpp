#ifndef GAME_DRAW_H
#define GAME_DRAW_H

#include "config.hpp"
#include "abstract/abs_drawer.hpp"

class FieldDraw final:public AbstractDrawer{
  public:
    FieldDraw(Game* game);
    ~FieldDraw();
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