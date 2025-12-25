#include "../../include/ncurses/hand_draw.hpp"
#include "../../include/ncurses/config.hpp"

HandDraw::HandDraw(Game* game):
AbstractDrawer(game){
  this->scr_height = 6;
  this->scr_width = game->spells_hand->get_size() * 10;

  init_pair(CARD_COLOR, COLOR_YELLOW, COLOR_BLACK);
  init_pair(SELECTED_CARD_COLOR, COLOR_WHITE, COLOR_BLUE);
}

HandDraw::~HandDraw(){}

void HandDraw::draw(){
  if (!this->win)
    return;
  int x = 0;
  wattron(this->win, CARD_COLOR);
  for (SpellCardInterface* card: *game->spells_hand->get_cards()){
    if (card == game->spells_hand->get_selected_card()){
      wattron(this->win, COLOR_PAIR(SELECTED_CARD_COLOR));
      this->draw_card(x, card);
      wattroff(this->win, COLOR_PAIR(SELECTED_CARD_COLOR));
    } else{
      this->draw_card(x, card);
    }
    x += 10;
  }
  wrefresh(this->win);
}

void HandDraw::draw_card(int x, SpellCardInterface* card){
  mvwprintw(this->win, 0, x, "|------|");
  mvwprintw(this->win, 1, x, "|%s", card->text());
  mvwprintw(this->win, 1, x+7, "|");
  for (int y = 2; y < scr_height-1; y++){
    mvwprintw(this->win, y, x, "|      |");
  }
  mvwprintw(this->win, scr_height - 1, x, "|------|");
}