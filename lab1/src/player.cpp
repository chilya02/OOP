#include "../include/player.hpp"

Player::Player(Cell* cell, int damage, int HP, int points):Entity(cell, damage, HP), points(points){
  this->mode = PlayerMode::Move;
}

PlayerMode Player::get_mode(){
  return this->mode;
}