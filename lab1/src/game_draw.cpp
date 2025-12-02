#include "../include/game_draw.hpp"

#include <vector>

GameDraw::GameDraw(Player* player, GameField* field, EnemyBuild* build)
    : player(player), field(field), build(build){
  
  this->scr_height = field->get_height() * CELL_HEIGHT * 2;
  this->scr_width = field->get_width() * CELL_WIDTH * 2;
  
  init_pair(DEFAULT_COLOR, COLOR_WHITE, COLOR_BLACK);
  init_pair(CELL_COLOR, COLOR_BLACK, COLOR_GREEN);
  init_pair(IMPASSABLE_COLOR, COLOR_WHITE, COLOR_RED);
  init_pair(SLOW_COLOR, COLOR_WHITE, COLOR_BLUE);
  init_pair(PLAYER_COLOR, COLOR_BLACK, COLOR_YELLOW);
  init_pair(AWAIT_COLOR, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(SLOWED_COLOR, COLOR_BLACK, COLOR_BLUE);
  init_pair(BUILD_COLOR, COLOR_BLACK, COLOR_WHITE);

  this->win = nullptr;
}

GameDraw::~GameDraw(){
  if (this->win)
    delwin(this->win);
}

int GameDraw::get_width(){
    return this->scr_width;
}

int GameDraw::get_height(){
    return this->scr_height;
}

void GameDraw::create_window(int y, int x){
  if (!this->win){
    this->win = newwin(this->scr_height, this->scr_width, y, x);
    this->draw();
  }
}

void GameDraw::del_window(){
    if (this->win){
        delwin(this->win);
        this->win = nullptr;
    }
}

void GameDraw::draw(){
  if (!this->win)
    return;
  for (int y = 0; y < this->field->get_height(); y++){
    for (int x = 0; x < this->field->get_width(); x++){
      Cell* cell = this->field->get_cell(y, x);
      this->draw_cell(cell);
    }
  }
  this->draw_player();
  if (this->player->can_act())
    this->draw_area();
  this->draw_build();
  wrefresh(this->win);
}

void GameDraw::move(int y, int x){
  if (!this->win)
    return;
  mvwin(this->win, y, x);
  wrefresh(this->win);
}

void GameDraw::draw_cell(Cell* cell){
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

  int y = cell->get_y();
  int x = cell->get_x();

  this->print(y, x, text, attr);
}

void GameDraw::draw_player(){
  const char* text = PLAYER_SYM;
  int attr = 0;

  Cell* cell = this->player->get_cell();
  int y = cell->get_y();
  int x = cell->get_x();

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

void GameDraw::print(int y, int x, const char* text, int attr){
  if (!this->win)
    return;
  int y_scr = y * CELL_HEIGHT * 2;
  int x_scr = x * CELL_WIDTH * 2;
  if (y >= this->scr_height | x >= this->scr_width)
    return;
  wattron(this->win, attr);
  mvwprintw(this->win, y_scr, x_scr, text);
  wattroff(this->win, attr);
}

void GameDraw::draw_area(){
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

void GameDraw::draw_area_cell(Cell* cell){
  if (cell->is_impassable())
    return;
  const char* text = CELL_SYM;
  if (cell->is_slow())
    text = SLOW_SYM;
  this->print(cell->get_y(), cell->get_x(), text, COLOR_PAIR(PLAYER_COLOR));
}

void GameDraw::draw_build(){
  Cell* cell = this->build->get_cell();
  this->print(cell->get_y(), cell->get_x(), BUILD_SYM, COLOR_PAIR(BUILD_COLOR));
}

std::vector<Cell*> GameDraw::get_move_area(){
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