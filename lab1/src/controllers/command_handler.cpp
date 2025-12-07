#include "../../include/controllers/command_handler.hpp"

CommandHandler::CommandHandler(
  Player* player, 
  Weapon* weapon,
  EnemiesController* enemies)
  :enemies_controller(enemies) 
  {
    this->player_controller = new PlayerController(player);
    this->weapon_controller = new WeaponController(weapon);
  }

CommandHandler::~CommandHandler(){
  if (this->player_controller)
    delete this->player_controller;
  if (this->weapon_controller)
    delete this->weapon_controller;
}
bool CommandHandler::handle_command(Command command){
  switch (command)
  {
    case Command::Attack:
      this->weapon_controller->set_center();
    case Command::Move:
      return this->player_controller->handle_mode(command);
    default:
      return this->handle_act(command);
  }
}

bool CommandHandler::handle_act(Command command){
  bool res = false;
  switch (player_controller->player->get_mode()){
    case PlayerMode::Move:
      return player_controller->move_player(command);
    case PlayerMode::FarFight:
    case PlayerMode::NearFight:
      res = weapon_controller->handle_command(command);
      break;
    default:
      return false;
  }
  if (command == Command::Ok && res){
    enemies_controller->hit_enemy();
    this->player_controller->set_stay();
  }
  return res;
}