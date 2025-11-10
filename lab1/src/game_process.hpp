#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include "game_view.hpp"
#include "player.hpp"
#include "game_field.hpp"

class GameProcess{
  enum class GameState{
    AwaitPlayer,
    AwaitEnemy,
    GameOver
  };
  public:
    GameProcess();
    ~GameProcess();
    void create_user_game();
    void create_random_game();
    void create_game(int height=10, int width=10, int period=3);
    void start();
  private:
    GameField* field;
    Player* player;
    GameView* view;
    GameState state;
    void move_player(int command);
    void loop();
    void set_player_pos();
};
#endif // GAME_PROCESS_H
