#include "game_view.hpp"
#include "player.hpp"

#include <ncurses.h>

#define DEFAULT_COLOR       0
#define CELL_COLOR          1
#define IMPASSABLE_COLOR    2
#define SLOW_COLOR          3
#define PLAYER_COLOR        4
#define AWAIT_COLOR         5

GameView::GameView(GameField* field, Player* player):field(field), player(player){
  noecho();
  start_color();
  init_pair(DEFAULT_COLOR, COLOR_BLACK, COLOR_BLACK);
  init_pair(CELL_COLOR, COLOR_BLACK, COLOR_GREEN);
  init_pair(IMPASSABLE_COLOR, COLOR_WHITE, COLOR_RED);
  init_pair(SLOW_COLOR, COLOR_BLACK, COLOR_BLUE);
  init_pair(PLAYER_COLOR, COLOR_BLACK, COLOR_YELLOW);
  init_pair(AWAIT_COLOR, COLOR_WHITE, COLOR_MAGENTA);
  this->draw();
}


void GameView::draw_player(int y, int x){
  attron(COLOR_PAIR(PLAYER_COLOR));
  if (this->player->status == EntityStatus::Await){
    attron(COLOR_PAIR(AWAIT_COLOR));
  }
  mvprintw(y, x, "ME");
}

void GameView::draw_cell(int y, int x, Cell* cell){

  const char* imp_text = "MM";
  const char* slow_text = "~~";
  const char* clean_text = "  ";
  const char* text;

  if (cell->is_impassable()){
    attron(COLOR_PAIR(IMPASSABLE_COLOR));
    text = imp_text;
  }
  else if (cell->is_slow()){
    attron(COLOR_PAIR(SLOW_COLOR));
    text = slow_text;
  }
  else{
    attron(COLOR_PAIR(CELL_COLOR));
    text = clean_text;
  }

  mvprintw(y, x, text);
}


void GameView::draw(){
  int x_scr = this->x_start;
  int y_scr = this->y_start;

  for (int y = 0; y < this->field->height; y++){
    x_scr = this->x_start;
    for (int x = 0; x < this->field->width; x++){
      Cell* cell = this->field->cells[y][x];
      if (this->player->cell == cell)
        this->draw_player(y_scr, x_scr);
      else
        this->draw_cell(y_scr, x_scr, cell);
      x_scr += 4;
    }
    y_scr += 2;
  }
  move(0, 0);

  wrefresh(stdscr);
}


bool GameView::calc_coordinates(){
  int row, col;

  getmaxyx(stdscr, row, col);
  
  if (this->row == row && this->col == col)
    return false;
  
  this->col = col;
  this->row = row;

  this->x_start = (col - this->field->width * 4) / 2;
  this->y_start = (row - this->field->height * 2) / 2;

  wclear(stdscr);
  return true;
}

void GameView::check_size(){
  if (this->calc_coordinates())
    this->draw();
}

void GameView::invalidate(){
  this->calc_coordinates();
  this->draw();
}
