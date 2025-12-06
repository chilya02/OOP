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
    return this->move_player(command);
    break;
  case EntityStatus::Stay:
    return true;
  default:
    return false;
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
