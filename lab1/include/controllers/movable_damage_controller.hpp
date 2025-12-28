#ifndef MOVABLE_DAMAGE_CONTROLLER_H
#define MOVABLE_DAMAGE_CONTROLLER_H

#include "movable_controller.hpp"
#include "../cell_objects/movable_damage.hpp"
#include "controller_interface.hpp"


class MovableDamageController: public ControllerInterface, public MovableController{
  public:
    MovableDamageController(MovableDamage*);
    ~MovableDamageController();
    bool handle_command(Command command) override;
  protected:
    MovableDamage* damage;
};

#endif // MOVABLE_DAMAGE_CONTROLLER_H