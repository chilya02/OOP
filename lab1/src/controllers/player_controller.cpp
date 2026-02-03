#include "../../include/controllers/player_controller.hpp"

PlayerController::PlayerController(Player* player)
:MovableController(player), player(player){}

bool PlayerController::handle_mode(Command command){
  switch (command){
  case Command::Attack:
    this->player->mode = PlayerMode::Attack;
    return true;
  case Command::Move:
    this->player->mode = PlayerMode::Move;
    return true;
  case Command::Cast:
    this->player->mode = PlayerMode::Cast;
    return true;
  default:
    return false;
  }
}

bool PlayerController::move_player(Command command){
  return MovableController::move_obj(command);
}

void PlayerController::set_stay(){
  this->player->status = EntityStatus::Stay;
}

void PlayerController::add_points(int count){
  this->player->points += count;
}