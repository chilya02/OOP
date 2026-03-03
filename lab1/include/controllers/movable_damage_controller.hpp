#ifndef MOVABLE_DAMAGE_CONTROLLER_H
#define MOVABLE_DAMAGE_CONTROLLER_H

#include "abstract/movable_controller.hpp"
#include "../models/cell_objects/abstract/movable_damage.hpp"
#include "interfaces/controller_interface.hpp"


class MovableDamageController: public ControllerInterface, public MovableController{
  public:
    MovableDamageController(MovableDamage*);
    ~MovableDamageController();
    bool handle_command(Command command) override;
    int get_damage();
  protected:
    MovableDamage* damage;
};

#endif // MOVABLE_DAMAGE_CONTROLLER_H