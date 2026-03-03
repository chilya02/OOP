#include "../../include/controllers/command_handler.hpp"

CommandHandler::CommandHandler(
  Game* game,
  EnemiesController* enemies)
  :enemies_controller(enemies),
  game(game) 
  {
    this->player_controller = new PlayerController(game->player);
    this->weapon_controller = new WeaponController(game->weapon);
    this->spells_hand_controller = new SpellsHandController(game->spells_hand, game->field, game->player);
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
  bool act = false;
  switch (player_controller->player->get_mode()){
    case PlayerMode::Move:
      return player_controller->move_player(command);
    case PlayerMode::Attack:
      if (command == Command::ChangeRange){
        this->player_controller->set_stay();
        return weapon_controller->change_mode();
      }
      res = weapon_controller->handle_command(command);
      act = res;
      break;
    case PlayerMode::Cast:
    if (spells_hand_controller->can_cast()){
      if (spells_hand_controller->is_active()){
        act = res = spells_hand_controller->handle_command(command);
      }
      else {
        res = spells_hand_controller->handle_command(command);
      }
    }
      break;
    default:
      return false;
  }
  if (command == Command::Ok && act){
    this->hit_enemies();
    this->player_controller->set_stay();
    if (game->player->get_mode() == PlayerMode::Cast){
      this->spells_hand_controller->remove_selected_card();
      this->spells_hand_controller->deactivate();
    }
  }
  return res;
}

void CommandHandler::hit_enemies(){
  int res = 0;
  switch (game->player->get_mode())
  { 
  case PlayerMode::Cast:
    if (!this->spells_hand_controller->get_active_card()->has_damage()){
      break;
    }
  case PlayerMode::Attack:
  res = this->enemies_controller->hit(
      this->game->get_attack_area(), 
      this->game->get_attack_damage());
    break;
  default:
    break;
  }
    this->player_controller->add_points(res);
}