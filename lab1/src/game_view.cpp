#include "../include/game_view.hpp"
#include "../include/player.hpp"
#include "../include/player_mode.hpp"

#include <vector>

#define DEFAULT_COLOR       0
#define CELL_COLOR          1
#define IMPASSABLE_COLOR    2
#define SLOW_COLOR          3
#define PLAYER_COLOR        4
#define AWAIT_COLOR         5
#define SLOWED_COLOR        6

#define PLAYER_SYM          "/\\"
#define SLOW_SYM            "~~"
#define IMPASSABLE_SYM      "MM"
#define CELL_SYM            "  "

#define CELL_WIDTH          2
#define CELL_HEIGHT         1

GameView::GameView(GameField* field, Player* player):field(field), player(player){
  this->field_scr_width = field->width * CELL_WIDTH * 2;
  this->field_scr_height = field->height * CELL_HEIGHT * 2;

  this->field_window = nullptr;
  this->q_menu_window = nullptr;

  this->calc_coordinates();
  
  noecho();
  start_color();
  wclear(stdscr);
  
  init_pair(DEFAULT_COLOR, COLOR_WHITE, COLOR_BLACK);
  init_pair(CELL_COLOR, COLOR_BLACK, COLOR_GREEN);
  init_pair(IMPASSABLE_COLOR, COLOR_WHITE, COLOR_RED);
  init_pair(SLOW_COLOR, COLOR_WHITE, COLOR_BLUE);
  init_pair(PLAYER_COLOR, COLOR_BLACK, COLOR_YELLOW);
  init_pair(AWAIT_COLOR, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(SLOWED_COLOR, COLOR_BLACK, COLOR_BLUE);
  this->draw();
}

GameView::~GameView(){
  delwin(this->field_window);
}

void GameView::draw_player(int y, int x){
  const char* text = PLAYER_SYM;
  int attr = 0;
  switch (this->player->get_status()) {
    case EntityStatus::Await:
      attr = COLOR_PAIR(AWAIT_COLOR) | A_BLINK;
      break;
    case EntityStatus::Slowed:
      attr = COLOR_PAIR(SLOWED_COLOR);
      break;
    default:
      attr = COLOR_PAIR(PLAYER_COLOR);
  }
  this->print(y, x, text, attr);
}

void GameView::draw_cell(int y, int x, Cell* cell){
  const char* text;
  int attr = 0;
  if (cell->is_impassable()){
    attr = COLOR_PAIR(IMPASSABLE_COLOR);
    text = IMPASSABLE_SYM;
  }
  else if (cell->is_slow()){
    attr = COLOR_PAIR(SLOW_COLOR);
    text = SLOW_SYM;
  }
  else{
    attr = COLOR_PAIR(CELL_COLOR);
    text = CELL_SYM;
  }
  this->print(y, x, text, attr);
}

void GameView::print(int y, int x, const char* text, int attr){
  int y_scr = y * CELL_HEIGHT * 2;
  int x_scr = x * CELL_WIDTH * 2;
  if (y >= this->field_scr_height | x >= this->field_scr_width)
    return;
  wattron(this->field_window, attr);
  mvwprintw(this->field_window, y_scr, x_scr, text);
  wattroff(this->field_window, attr);
}

void GameView::draw(){
  if (!this->is_visible)
    return;

  for (int y = 0; y < this->field->height; y++){
    for (int x = 0; x < this->field->width; x++){
      Cell* cell = this->field->cells[y][x];
      if (this->player->get_cell() == cell)
        this->draw_player(y, x);
      else
        this->draw_cell(y, x, cell);
    }
  }
  if (this->player->can_act())
    this->draw_area();
  move(0, 0);
  wrefresh(this->field_window);
  wrefresh(stdscr);
}

void GameView::draw_area(){
  std::vector<Cell*> res;
  switch (this->player->get_mode()){
  case PlayerMode::Move:
    res = this->get_move_area();
    break;
  case PlayerMode::NearFight:
    break;
  case PlayerMode::FarFight:
    break;
  default:
    break;
  }
  for (auto cell: res){
    draw_area_cell(cell);
  }
}

void GameView::draw_area_cell(Cell* cell){
  if (cell->is_impassable())
    return;
  const char* text = CELL_SYM;
  if (cell->is_slow())
    text = SLOW_SYM;
  this->print(cell->get_y(), cell->get_x(), text, COLOR_PAIR(PLAYER_COLOR));
}

std::vector<Cell*> GameView::get_move_area(){
  Cell* anchor = this->player->get_cell();
  std::vector<Cell*> res;
  Cell* cell = anchor->get_bottom();
  if (cell)
    res.push_back(cell);
  cell = anchor->get_top();
  if (cell)
    res.push_back(cell);
  cell = anchor->get_left();
  if (cell)
    res.push_back(cell);
  cell = anchor->get_right();
  if (cell)
    res.push_back(cell);
  return res;
}

void GameView::del_windows(){
  if (this->field_window){
    delwin(this->field_window);
    this->field_window = nullptr;
    wclear(stdscr);
  }
}

void GameView::create_windows(){
  if (!this->field_window){
    this->field_window = newwin(this->field_scr_height, this->field_scr_width, this->y_start, this->x_start);
    this->draw();
  }
}

bool GameView::calc_coordinates(){
  int row, col;

  getmaxyx(stdscr, row, col);
  
  if (this->row == row && this->col == col)
    return false;
  
  this->col = col;
  this->row = row;
  
  this->x_start = (col - this->field_scr_width) / 2;
  this->y_start = (row - this->field_scr_height) / 2;
  
  if (col < this->field_scr_width + 5 || row < this->field_scr_height + 5){
    del_windows();
    this->is_visible = false;
  } else {
    this->is_visible = true;
    this->create_windows();
  }

  return true;
}

void GameView::move_field(){
  mvwin(this->field_window, this->y_start, this->x_start);
  wclear(stdscr);
  wrefresh(stdscr);
  wrefresh(this->field_window);
  move(0,0);
}

void GameView::check_size(){
  if (this->calc_coordinates()){
    if (this->is_visible)
      this->move_field();
  }
}

void GameView::invalidate(){
  this->check_size();
  this->draw();
}
