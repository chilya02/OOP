#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "../models/cell_objects/player.hpp"
#include "../models/cell_objects/enemy.hpp"
#include "abstract/movable_controller.hpp"

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