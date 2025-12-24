#include "../../include/cell_objects/player.hpp"

Player::Player(Cell* cell, int damage, int HP, int points):Entity(cell, damage, HP), points(points){
  this->mode = PlayerMode::Move;
}
Player::~Player(){}

PlayerMode Player::get_mode(){
  return this->mode;
}

int Player::get_score(){
  return this->points;
}