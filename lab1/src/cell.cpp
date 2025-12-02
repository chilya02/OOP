#include "../include/cell.hpp"

Cell::Cell(int y, int x):y(y), x(x){
  this->top = NULL;
  this->bottom = NULL;
  this->right = NULL;
  this->left = NULL;
}

Cell::~Cell(){

}

Cell::Cell(const Cell& other):y(other.y), x(other.x){

  this->impassable = false;
  this->slow = false;

  this->top = other.top;
  if (this->top)
    this->top->bottom = this;

  this->bottom = other.bottom;
  if (this->bottom)
    this->bottom->top = this;

  this->right = other.right;
  if (this->right)
    this->right->left = this;

  this->left = other.left;
  if (this->left)
    this->left->right = this;
}

int Cell::get_y(){
  return this->y;
}

int Cell::get_x(){
  return this->x;
}

bool Cell::is_impassable(){
  return this->impassable;
}

bool Cell::is_slow(){
  return this->slow;
}

bool Cell::is_busy(){
  return this->busy;
}

Cell* Cell::get_top(){
  return this->top;
}
Cell* Cell::get_bottom(){
  return this->bottom;
}
Cell* Cell::get_right(){
  return this->right;
}
Cell* Cell::get_left(){
  return this->left;
}

Cell*** Cell::create_matrix(int height, int width){
    Cell*** cells = new Cell ** [height];
    for (int y = 0; y < height; y++){
      cells[y] = new Cell * [width];
      for (int x = 0; x < width; x++){
        cells[y][x] = new Cell(y, x);
        if (y >= 1){
          cells[y-1][x]->bottom = cells[y][x];
          cells[y][x]->top = cells[y-1][x];
        }
        if (x >= 1){
          cells[y][x-1]->right = cells[y][x];
          cells[y][x]->left = cells[y][x-1];
        }
      }
    }
    return cells;
  }

std::vector<Cell*> Cell::get_neighbors(){
  std::vector<Cell*> res;
  if (this->bottom && !this->bottom->impassable)
    res.push_back(this->bottom);
  if (this->top && !this->top->impassable)
    res.push_back(this->top);
  if (this->left && !this->left->impassable)
    res.push_back(this->left);
  if (this->right && !this->right->impassable)
    res.push_back(this->right);
  return res;
}

std::vector<Cell*> Cell::get_free_neighbors(){
  std::vector<Cell*> res;
  if (this->bottom && !this->bottom->busy && !this->bottom->impassable)
    res.push_back(this->bottom);
  if (this->top && !this->top->busy && !this->top->impassable)
    res.push_back(this->top);
  if (this->left && !this->left->busy && !this->left->impassable)
    res.push_back(this->left);
  if (this->right && !this->right->busy && !this->right->impassable)
    res.push_back(this->right);
  return res;
}