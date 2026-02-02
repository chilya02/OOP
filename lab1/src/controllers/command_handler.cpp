#include "../../include/controllers/command_handler.hpp"

CommandHandler::CommandHandler(
  Player* player, 
  Weapon* weapon,
  SpellsHand* hand,
  GameField* field,
  EnemiesController* enemies)
  :enemies_controller(enemies) 
  {
    this->player_controller = new PlayerController(player);
    this->weapon_controller = new WeaponController(weapon);
    this->spells_hand_controller = new SpellsHandController(hand, field, player);
  }

CommandHandler::~CommandHandler(){
  if (this->player_controller)
    delete this->player_controller;
  if (this->weapon_controller)
    delete this->weapon_controller;
}
bool CommandHandler::handle_command(Command command){
  switch (command)
  { case Command::Undefined:
      return false;
    case Command::Attack:
    case Command::Move:
    case Command::Cast:
      return this->player_controller->handle_mode(command);
    default:
      return this->handle_act(command);
  }
}

bool CommandHandler::handle_act(Command command){
  bool res = false;
  bool hit = false;
  switch (player_controller->player->get_mode()){
    case PlayerMode::Move:
      return player_controller->move_player(command);
    case PlayerMode::Attack:
      if (command == Command::ChangeRange){
        this->player_controller->set_stay();
        return weapon_controller->change_mode();
      }
      res = weapon_controller->handle_command(command);
      hit = res;
      break;
    case PlayerMode::Cast:
    if (spells_hand_controller->can_cast()){
      if (spells_hand_controller->is_active()){
        hit = true;
      }
      res = spells_hand_controller->handle_command(command);
    }
      break;
    default:
      return false;
  }
  if (command == Command::Ok && hit){
    this->hit_enemies();
    this->player_controller->set_stay();
  }
  return res;
}

void CommandHandler::hit_enemies(){
  int res = 0;
  switch (this->player_controller->player->get_mode()){
  case PlayerMode::Attack:
    res = this->enemies_controller->hit(
      this->weapon_controller->get_area(), 
      this->weapon_controller->get_damage());
    break;
  case PlayerMode::Cast:
    //res = this->enemies_controller->hit();
    break;
  default:
    break;
  }
  this->player_controller->add_points(res);
}