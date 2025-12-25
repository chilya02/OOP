#ifndef SPELLS_HAND_CONTROLLER_H
#define SPELLS_HAND_CONTROLLER_H

#include "../common/game_commands.hpp"
#include "../spells/spells_hand.hpp"

class SpellsHandController{
  public:
    SpellsHandController(SpellsHand* spells_hand);
    ~SpellsHandController();
    bool can_cast();
    bool handle_command(Command command);
  private:
    SpellsHand* spells_hand;
};

#endif //SPELLS_HAND_CONTROLLER_H