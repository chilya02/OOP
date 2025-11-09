#include "player.hpp"

Player::Player(int , int , int points):points(points){};

std::string Player::view(){
  switch (this->status){
    case EntityStatus::Await:
      return std::string("\033[5;31mЯR\033[0m");
    case EntityStatus::Slowed:
      return std::string("\033[2;47;31m~~\033[0m");
    case EntityStatus::Stay:
      return std::string("\033[2;47;31mЯR\033[0m");
  }
}
