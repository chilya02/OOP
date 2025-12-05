#include "../../include/ncurses/game_draw.hpp"

GameDraw::GameDraw(Game* game)
    :AbstractDrawer(game){
  
  this->scr_height = game->field->get_height() * CELL_HEIGHT * 2;
  this->scr_width = game->field->get_width() * CELL_WIDTH * 2;
  
  init_pair(DEFAULT_COLOR, COLOR_WHITE, COLOR_BLACK);
  init_pair(CELL_COLOR, COLOR_BLACK, COLOR_GREEN);
  init_pair(IMPASSABLE_COLOR, COLOR_WHITE, COLOR_RED);
  init_pair(SLOW_COLOR, COLOR_WHITE, COLOR_BLUE);
  init_pair(PLAYER_COLOR, COLOR_BLACK, COLOR_YELLOW);
  init_pair(AWAIT_COLOR, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(SLOWED_COLOR, COLOR_BLACK, COLOR_BLUE);
  init_pair(BUILD_COLOR, COLOR_BLACK, COLOR_WHITE);
  init_pair(ENEMY_COLOR, COLOR_RED, COLOR_WHITE);
}

GameDraw::~GameDraw(){
  if (this->win)
    delwin(this->win);
}

void GameDraw::draw(){
  if (!this->win)
    return;
  for (int y = 0; y < this->game->field->get_height(); y++){
    for (int x = 0; x < this->game->field->get_width(); x++){
      Cell* cell = this->game->field->get_cell(y, x);
      draw_cell(cell);
    }
  }
  draw_player();
  if (this->game->player->can_act())
    draw_area();
  draw_building();
  draw_enemies();
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

  Cell* cell = game->player->get_cell();
  int y = cell->get_y();
  int x = cell->get_x();

  switch (game->player->get_status()) {
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
  if (y >= this->scr_height || x >= this->scr_width)
    return;
  wattron(win, attr);
  mvwprintw(win, y_scr, x_scr, "%s", text);
  wattroff(win, attr);
}

void GameDraw::draw_area(){
  std::vector<Cell*> res;
  switch (game->player->get_mode()){
  case PlayerMode::Move:
    res = game->player->get_cell()->get_free_neighbors();
    break;
  case PlayerMode::NearFight:
    break;
  case PlayerMode::FarFight:
    break;
  default:
    break;
  }
  for (auto cell: res){
    this->draw_area_cell(cell);
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

void GameDraw::draw_building(){
  Cell* cell = this->game->enemy_building->get_cell();
  this->print(cell->get_y(), cell->get_x(), BUILD_SYM, COLOR_PAIR(BUILD_COLOR));
}

void GameDraw::draw_enemies(){
  for (Enemy* enemy: *game->enemies){
    Cell* cell = enemy->get_cell();
    this->print(cell->get_y(), cell->get_x(), ENEMY_SYM, COLOR_PAIR(ENEMY_COLOR));
  }
}