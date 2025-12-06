#include "../../include/ncurses/progress_draw.hpp"

ProgressDraw::ProgressDraw(Game* game)
:AbstractDrawer(game){
  this->scr_height = game->field->get_height() * CELL_HEIGHT * 2;
  this->scr_width = 10;
}

ProgressDraw::~ProgressDraw(){}

void ProgressDraw::draw(){
  if (!this->win)
    return;
  wclear(this->win);
  this->draw_player_info();
  this->draw_enemies_HP();
  wrefresh(this->win);
}

void ProgressDraw::draw_player_info(){
  mvwprintw(this->win, 0, 0, "Player:");
  mvwprintw(this->win, 1, 0, "HP: %d", this->game->player->get_HP());
  //this->draw_progress_bar(2,0, this->game->player);
}

void ProgressDraw::draw_enemies_HP(){
  int count = 1;
  mvwprintw(this->win, 3, 0, "Enemies:");
  for (Enemy* enemy: *this->game->enemies){
    if (enemy->is_alive()){
      mvwprintw(this->win, 3+count, 0, "%d: %d", count, enemy->get_HP());
      count++;
    }
  }
}

void ProgressDraw::draw_progress_bar(int y, int x, Entity* entity){
  wattron(this->win, COLOR_PAIR(ENEMY_COLOR));
  wmove(this->win, y, x);
  for (int i = 0; i < entity->get_HP()/10; i++){
    waddch(this->win, ' ');
  }
  wattroff(this->win, COLOR_PAIR(ENEMY_COLOR));
}