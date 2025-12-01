#include "game_view.hpp"
#include "player.hpp"

#define DEFAULT_COLOR       0
#define CELL_COLOR          1
#define IMPASSABLE_COLOR    2
#define SLOW_COLOR          3
#define PLAYER_COLOR        4
#define AWAIT_COLOR         5
#define SLOWED_COLOR        6

GameView::GameView(GameField* field, Player* player):field(field), player(player){
  this->scr_width = field->width * 4;
  this->scr_height = field->height * 2;

  this->field_window = nullptr;
  this->q_menu_window = nullptr;

  this->calc_coordinates();
  
  noecho();
  start_color();
  wclear(stdscr);
  
  init_pair(DEFAULT_COLOR, COLOR_WHITE, COLOR_BLACK);
  init_pair(CELL_COLOR, COLOR_BLACK, COLOR_GREEN);
  init_pair(IMPASSABLE_COLOR, COLOR_WHITE, COLOR_RED);
  init_pair(SLOW_COLOR, COLOR_BLACK, COLOR_BLUE);
  init_pair(PLAYER_COLOR, COLOR_BLACK, COLOR_YELLOW);
  init_pair(AWAIT_COLOR, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(SLOWED_COLOR, COLOR_BLACK, COLOR_BLUE);
  this->draw();
}

GameView::~GameView(){
  delwin(this->field_window);
}

void GameView::draw_player(int y, int x){
  int pair = 0;
  switch (this->player->get_status()) {
    case EntityStatus::Await:
      pair = COLOR_PAIR(AWAIT_COLOR);
      break;
    case EntityStatus::Slowed:
      pair = COLOR_PAIR(SLOWED_COLOR);
      break;
    default:
      pair = COLOR_PAIR(PLAYER_COLOR);
  }
  wattron(this->field_window, pair);
  mvwprintw(this->field_window, y, x, "/\\");
}

void GameView::draw_cell(int y, int x, Cell* cell){

  const char* imp_text = "MM";
  const char* slow_text = "~~";
  const char* clean_text = "  ";
  const char* text;

  int pair = 0;
  if (cell->is_impassable()){
    pair = COLOR_PAIR(IMPASSABLE_COLOR);
    text = imp_text;
  }
  else if (cell->is_slow()){
    pair = COLOR_PAIR(SLOW_COLOR);
    text = slow_text;
  }
  else{
    pair = COLOR_PAIR(CELL_COLOR);
    text = clean_text;
  }
  wattron(this->field_window, pair | A_NORMAL);
  mvwprintw(this->field_window, y, x, text);
}

void GameView::draw(){
  if (!this->is_visible)
    return;
  int x_scr = 0;
  int y_scr = 0;

  for (int y = 0; y < this->field->height; y++){
    x_scr = 0;
    for (int x = 0; x < this->field->width; x++){
      Cell* cell = this->field->cells[y][x];
      if (this->player->get_cell() == cell)
        this->draw_player(y_scr, x_scr);
      else
        this->draw_cell(y_scr, x_scr, cell);
      x_scr += 4;
    }
    y_scr += 2;
  }
  move(0, 0);
  wrefresh(this->field_window);
  wrefresh(stdscr);
}

void GameView::del_windows(){
  if (this->field_window){
    delwin(this->field_window);
    this->field_window = nullptr;
    wclear(stdscr);
  }
}

void GameView::create_windows(){
  if (!this->field_window)
    this->field_window = newwin(this->scr_height, this->scr_width, this->y_start, this->x_start);
    this->draw();
}

bool GameView::calc_coordinates(){
  int row, col;

  getmaxyx(stdscr, row, col);
  
  if (this->row == row && this->col == col)
    return false;
  
  this->col = col;
  this->row = row;
  
  this->x_start = (col - this->scr_width) / 2;
  this->y_start = (row - this->scr_height) / 2;
  
  if (col < this->scr_width + 5 || row < this->scr_height + 5){
    del_windows();
    this->is_visible = false;
  } else {
    this->is_visible = true;
    this->create_windows();
  }

  return true;
}

void GameView::move_field(){
  if (!this->is_visible)
    return;
  mvwin(this->field_window, this->y_start, this->x_start);
  wclear(stdscr);
  wrefresh(stdscr);
  wrefresh(this->field_window);
  move(0,0);
}

void GameView::check_size(){
  if (this->calc_coordinates()){
    this->move_field();
  }
}

void GameView::invalidate(){
  this->check_size();
  this->draw();
}
