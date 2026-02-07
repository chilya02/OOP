#ifndef SPELLS_HAND_CONTROLLER_H
#define SPELLS_HAND_CONTROLLER_H

#include "../common/game_commands.hpp"
#include "../models/spells/spells_hand.hpp"
#include "../models/cells/game_field.hpp"
#include "../models/cell_objects/player.hpp"

class SpellsHandController{
  public:
    SpellsHandController(SpellsHand* spells_hand, GameField* field, Player* player);
    ~SpellsHandController();
    bool can_cast();
    bool handle_command(Command command);
    bool is_active();
    void deactivate();
    void remove_selected_card();
    SpellCardInterface*get_active_card();
  private:
    SpellsHand* spells_hand;
    GameField* field;
    Player* player;

    ControllerInterface* get_active_controller();
};

#endif //SPELLS_HAND_CONTROLLER_H