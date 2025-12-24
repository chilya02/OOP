#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "../cell_objects/player.hpp"
#include "../cell_objects/weapon.hpp"
#include "../cell_objects/enemy.hpp"
#include "movable_controller.hpp"

class PlayerController : public MovableController{
  public:
    PlayerController(Player* player);
  private:
    bool handle_mode(Command command);
    bool move_player(Command command);
    void set_stay();
    void add_points(int count = 50);
    Player* player;
  
  friend class CommandHandler;
};
#endif //PLAYER_CONTROLLER_H