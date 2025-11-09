#include "game_field.hpp"
#include "cell.hpp"
#include "impassable_cell.hpp"
#include "slow_cell.hpp"

GameField::GameField(int height, int width):width(width), height(height) {
  if (width < 10 || height < 10 || width > 25 || height > 25){
    throw "Game field should be grater than 10x10 and less then 25x25";
  }

  srand(time(NULL));
  
  this->cells = Cell().create_matrix(height, width);
  this->create_impassable_cells();
  this->create_slow_cells();
}

Cell** GameField::get_random_cell(){
  int index = width + (rand() % (this->size() - 2 * width));
  Cell**pointer = &this->cells[index / width][index % width];
  return pointer;
}

void GameField::create_impassable_cells(){
  int impassable_cells_count = this->size() / 20;
  for (int i = 0; i < impassable_cells_count; i++){
    Cell** pointer = this->get_random_cell();
    *pointer = new ImpassableCell(**pointer);
  }
}

void GameField::create_slow_cells(){
  int slow_cells_count = this->size() / 15;
 
  for (int i = 0; i < slow_cells_count; i++){
    Cell** pointer = this->get_random_cell();
    *pointer = new SlowCell(**pointer);
  }
}

int GameField::size(){
  return this->height * this->width;
}



