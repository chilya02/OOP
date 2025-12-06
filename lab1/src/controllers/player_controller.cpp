#include "../../include/controllers/player_controller.hpp"
#include "../../include/cell_objects/entity_status.hpp"

PlayerController::PlayerController(Player* player):player(player){}

bool PlayerController::handle_command(Command command){
switch (this->player->status){
  case EntityStatus::Slowed:
    this->player->status = EntityStatus::Stay;
    return true;
    break;
  case EntityStatus::Await:
    return this->handle_mode(command);
    break;
  case EntityStatus::Stay:
    return true;
  default:
    return false;
  }
}

bool PlayerController::handle_mode(Command command){
  switch (command){
  case Command::Attack:
    if (this->player->mode == PlayerMode::NearFight)
      this->player->mode = PlayerMode::FarFight;
    else 
      this->player->mode = PlayerMode::NearFight;
    return true;
  case Command::Move:
    this->player->mode = PlayerMode::Move;
    return true;
  default:
    return handle_act(command);
  }
}

bool PlayerController::handle_act(Command command){
  switch (this->player->get_mode()){
  case PlayerMode::Move:
    return this->move_player(command);
    break;

  default:
    break;
  }
}

bool PlayerController::move_player(Command command){
  bool flag = false;
  switch (command){
    case Command::Up:
      flag = flag || this->player->move_up();
      break;
    case Command::Down:
      flag = flag || this->player->move_down();
      break;
    case Command::Right:
      flag = flag || this->player->move_right();
      break;
    case Command::Left:
      flag = flag || this->player->move_left();
      break;
    default:
      break;
  }
  return flag;
}
