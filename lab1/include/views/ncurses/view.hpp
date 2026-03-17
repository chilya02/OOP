#ifndef NCURSES_GAME_VIEW_H
#define NCURSES_GAME_VIEW_H

#include "../interfaces/view_interface.hpp"
#include "interfaces/draw_interface.hpp"
#include "menu_draw.hpp"
#include "../../models/app.hpp"

#include "game_draw.hpp"

class NcursesView final:public ViewInterface{
  public:
    NcursesView(App*);
    ~NcursesView() final;
    void invalidate() override;
    void check_size() override;

  private:
    IDraw* get_active_draw();
    GameDraw* game_drawer;
    MenuDraw* load_menu_draw;
    MenuDraw* quit_menu_draw;
    MenuDraw* game_over_draw;
    App* app;
    AppState prev_state;
};

#endif
