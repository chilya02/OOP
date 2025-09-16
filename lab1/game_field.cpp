#include "game_field.h"
#include "cell.h"

GameField::GameField(int width, int height){
  width_ = width;
  height_ = height;
  cells_ = new Cell ** [height];
  for (int y = 0; y < height; y++){
    cells_[y] = new Cell * [width];

    for (int x = 0; x < width; x++){
      cells_[y][x] = new Cell; 
    }
  }
}
