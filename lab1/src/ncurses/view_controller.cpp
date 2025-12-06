#include "../../include/ncurses/view_controller.hpp"

NcursesViewController::NcursesViewController(Game* game){
  
  start_color();
  wclear(stdscr);
  
  this->field_drawer = new GameDraw(game);
  this->progress_drawer = new ProgressDraw(game);

  this->calc_coordinates();
  
  this->draw();
}

NcursesViewController::~NcursesViewController(){
  if (this->field_drawer)
    delete this->field_drawer;
  if (this->progress_drawer)
    delete this->progress_drawer;
}


void NcursesViewController::draw(){
  if (!this->is_visible)
    return;
  this->field_drawer->draw();
  this->progress_drawer->draw();
  move(0, 0);
  wrefresh(stdscr);
}

void NcursesViewController::del_windows(){
  if (this->is_visible){
    this->field_drawer->del_window();
    this->progress_drawer->del_window();
    wclear(stdscr);
  }
}

void NcursesViewController::create_windows(){
  this->field_drawer->create_window(this->field_y, this->field_x);
  this->progress_drawer->create_window(this->field_y, PROGRESS_MARGIN_LR);
}

bool NcursesViewController::calc_coordinates(){
  int row, col;

  getmaxyx(stdscr, row, col);
  
  if (this->row == row && this->col == col)
    return false;
  
  this->col = col;
  this->row = row;
  
  int field_width = this->field_drawer->get_width();
  int field_height = this->field_drawer->get_height();

  this->field_x = (col - field_width) / 2;
  this->field_y = (row - field_height) / 2;

  int min_field_x = this->progress_drawer->get_width() + 2 * PROGRESS_MARGIN_LR;

  field_x = field_x > min_field_x ? field_x : min_field_x;
  
  if (col < field_width + this->progress_drawer->get_width() + 2 * PROGRESS_MARGIN_LR || row < field_height + 2){
    if (this->is_visible){
      del_windows();
      this->is_visible = false;
    }
  } else {
      if (!this->is_visible){
      this->is_visible = true;
      this->create_windows();
    }
  }

  return true;
}

void NcursesViewController::move_field(){
  wclear(stdscr);
  wrefresh(stdscr);
  this->field_drawer->move(this->field_y, this->field_x);
  this->progress_drawer->move(this->field_y, PROGRESS_MARGIN_LR);
  wrefresh(stdscr);
  move(0,0);
}

void NcursesViewController::check_size(){
  if (this->calc_coordinates()){
    if (this->is_visible)
      this->move_field();
  }
}

void NcursesViewController::invalidate(){
  this->check_size();
  this->draw();
}
