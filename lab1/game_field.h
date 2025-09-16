#include "cell.h"
#ifndef GAME_FIELD_H
#define GAME_FIELD_H

class GameField{
  public:
    GameField(int width, int height);
  private:
    int width_;
    int height_;
    Cell ***cells_;
};
#endif // GAME_FIELD
