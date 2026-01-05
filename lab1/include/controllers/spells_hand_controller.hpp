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
    bool is_active();
    void deactivate();
  private:
    SpellsHand* spells_hand;
    bool active;

    ControllerInterface* get_active_controller();
};

#endif //SPELLS_HAND_CONTROLLER_H