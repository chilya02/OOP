#ifndef MENU_DRAW_H
#define MENU_DRAW_H
#include "../../models/menus/interfaces/menu_interface.hpp"
#include "abstract/abs_drawer.hpp"
#include "interfaces/draw_interface.hpp"
#include "config.hpp"
#include <ncurses.h>

class MenuDraw: public IDraw, public AbstractDrawer{
  public:
    MenuDraw(IMenu*, std::string name);
    void invalidate() override;
    void check_size() override;
  private:
    std::string name;
    int width;
    int height;
    int col;
    int row;
    int x; 
    int y;
    bool calc_coordinates();
    void draw() override;
    IMenu* menu;
};

#endif //MENU_DRAW_H