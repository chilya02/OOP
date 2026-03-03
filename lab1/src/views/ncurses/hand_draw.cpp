#include "../../../include/views/ncurses/hand_draw.hpp"
#include "../../../include/views/ncurses/config.hpp"

#include <ncurses.h>
#include <sstream>

HandDraw::HandDraw(Game* game):
AbstractDrawer(game), prev_size(0){
  this->scr_height = 6;
  this->scr_width = game->spells_hand->get_size() * 10;

  init_pair(CARD_COLOR, COLOR_WHITE, -1);
  init_pair(SELECTED_CARD_COLOR, COLOR_WHITE, COLOR_BLUE);
}

HandDraw::~HandDraw(){}

void HandDraw::draw(){
  if (!this->win)
    return;
  int size = game->spells_hand->get_cards().size();
  if (size != prev_size){
    prev_size = size;
    wclear(this->win);
  }
  int x = 0;
  wattron(this->win, COLOR_PAIR(CARD_COLOR));
  for (SpellCardInterface* card: game->spells_hand->get_cards()){
    if (game->player->get_mode() == PlayerMode::Cast && card == game->spells_hand->get_selected_card()){
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

  std::stringstream ss(game->spells_hand->get_name(card));
  std::string item;
  int count = 0;
   while(std::getline(ss, item, ' ')) {
      int left_pad = 3 + item.length() / 2;
      int right_pad = 3 - item.length() / 2;
      const char* str = item.c_str();
        mvwprintw(this->win, 1 + count, x, "|%*s%*s|", left_pad, str, right_pad, "");
        count++;
    }
  for (int y = 1 + count; y < scr_height-1; y++){
    mvwprintw(this->win, y, x, "|      |");
  }
  mvwprintw(this->win, scr_height - 1, x, "|------|");
}
