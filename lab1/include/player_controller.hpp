#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "player.hpp"
#include "game_commands.hpp"

class PlayerController{
  public:
    PlayerController(Player* player);
    bool handle_command(Command command);
    bool move_player(Command command);
  private:
    Player* player;
};
#endif //PLAYER_CONTROLLER_H