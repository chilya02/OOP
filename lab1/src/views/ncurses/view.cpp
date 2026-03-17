#include "../../../include/views/ncurses/view.hpp"

NcursesView::NcursesView(App* app):app(app), prev_state(app->get_state()){
  
  start_color();
  use_default_colors();
  wclear(stdscr);
  init_pair(DEFAULT_COLOR, COLOR_WHITE, COLOR_BLACK);
  init_pair(SELECTED_COLOR, COLOR_BLACK, COLOR_WHITE);

  this->load_menu_draw = new MenuDraw(app->get_load_menu(), "LOAD MENU");
  this->quit_menu_draw = new MenuDraw(app->get_quit_menu(), "  PAUSE");
  this->game_over_draw = new MenuDraw(app->get_game_over_menu(), "GAME OVER");
}

NcursesView::~NcursesView(){
  if (this->game_drawer)
    delete this->game_drawer;
}

void NcursesView::check_size(){
  this->get_active_draw()->check_size();
}

void NcursesView::invalidate(){
  this->get_active_draw()->invalidate();
}


IDraw* NcursesView::get_active_draw(){

  if (this->prev_state != app->get_state()){
    this->prev_state = app->get_state();
    wclear(stdscr);
    wrefresh(stdscr);
  }

  switch (app->get_state()){
    case AppState::Load:
      return this->load_menu_draw;
    case AppState::Play:
        if (!this->game_drawer){
          this->game_drawer = new GameDraw(app->get_game());
        }
      return this->game_drawer;
    case AppState::Quit:
      return this->quit_menu_draw;  
    case AppState::GameOver:
        if (this->game_drawer){
          delete this->game_drawer;
          this->game_drawer = nullptr;
        }
        return this->game_over_draw;
  }

}