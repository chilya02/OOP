#include "player.hpp"

Player::Player(int , int , int points):points(points){};

PlayerMode Player::get_mode(){
  return this->mode;
}