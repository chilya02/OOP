#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "player_controller.hpp"
#include "weapon_controller.hpp"
#include "enemies_controller.hpp"
#include "spells_hand_controller.hpp"

class CommandHandler{
  public:
    CommandHandler(Player*, Weapon*, SpellsHand*, EnemiesController*);
    ~CommandHandler();
    bool handle_command(Command command);
  private:
    bool handle_act(Command command);
    PlayerController* player_controller;
    WeaponController* weapon_controller;
    EnemiesController* enemies_controller;
    SpellsHandController* spells_hand_controller;
};

#endif // COMMAND_HANDLER_H