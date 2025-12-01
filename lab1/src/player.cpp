#include "../include/player.hpp"

Player::Player(int, int, int points):points(points){
    this->mode = PlayerMode::Move;
}

Player::Player(Cell* cell, int, int, int points):points(points){
  this->cell = cell;
}

PlayerMode Player::get_mode(){
  return this->mode;
}