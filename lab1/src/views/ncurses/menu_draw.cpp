#include "../../../include/views/ncurses/menu_draw.hpp"

MenuDraw::MenuDraw(IMenu* menu, std::string name)
:AbstractDrawer(), menu(menu), name(name){
  this->width = 10;
  this->height = this->menu->size() + 2;
  this->calc_coordinates();
  this->win = newwin(height, width, y, x);
}

void MenuDraw::draw(){
  
  std::vector<std::string> names = menu->get_names();
  wattron(this->win, COLOR_PAIR(DEFAULT_COLOR));
  mvwprintw(this->win, 0, 0, "%s", this->name.c_str());
  for (int i = 0; i < menu->size(); i++){
    std::string element = names[i];
    if (i == menu->get_selected_index()){
      wattroff(this->win, COLOR_PAIR(DEFAULT_COLOR));
      wattron(this->win, COLOR_PAIR(SELECTED_COLOR));
      mvwprintw(this->win, i + 2, 0, " %-9s", element.c_str());
      wattroff(this->win, COLOR_PAIR(SELECTED_COLOR));
      wattron(this->win, COLOR_PAIR(DEFAULT_COLOR));
    }
    else{
      mvwprintw(this->win, i + 2, 0, " %-9s", element.c_str());
    }
  }
  wattroff(this->win, COLOR_PAIR(DEFAULT_COLOR));
  
  wmove(stdscr, 0,0);
  wrefresh(this->win);
  wrefresh(stdscr);
}

void MenuDraw::invalidate(){
  this->check_size();
  this->draw();
};

void MenuDraw::check_size(){
  if (this->calc_coordinates()){
    this->move(y, x);
    wclear(stdscr);
    wrefresh(stdscr);
    this->draw();
    wrefresh(stdscr);
  }
}

bool MenuDraw::calc_coordinates(){
  int row, col;

  getmaxyx(stdscr, row, col);
  
  if (this->row == row && this->col == col)
    return false;
  
  this->col = col;
  this->row = row;
  this->x = (col - width) / 2;
  this->y = (row - height) / 2;
  return true;
}