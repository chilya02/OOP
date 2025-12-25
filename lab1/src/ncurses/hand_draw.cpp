#include "../../include/ncurses/hand_draw.hpp"

HandDraw::HandDraw(Game* game):
AbstractDrawer(game){
  this->scr_height = 5;
  this->scr_width = game->spells_hand->get_size() * 5;
}

HandDraw::~HandDraw(){}

void HandDraw::draw(){

}