  #ifndef MOVABLE_DAMAGE_CARD_H
  #define MOVABLE_DAMAGE_CARD_H

  #include "abstract_card.hpp"
  #include "../../../controllers/movable_damage_controller.hpp"
  #include "../../cell_objects/abstract/movable_damage.hpp"

  class MovableDamageCard: public AbstractCard{
    public:
      MovableDamageCard();
      MovableDamageController* get_controller() override;
      MovableDamage* get_spell();
    protected:
      MovableDamage* spell;
      MovableDamageController* controller;
  };

  #endif //MOVABLE_DAMAGE_CARD_H