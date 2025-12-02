#ifndef CELL_H
#define CELL_H

#include <stdlib.h>
#include <vector>

class Cell{
  public:
    Cell(int y, int x);
    virtual ~Cell();
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    bool is_impassable();
    bool is_slow();
    bool is_busy();
    int get_y();
    int get_x();
    Cell* get_top();
    Cell* get_bottom();
    Cell* get_right();
    Cell* get_left();
    std::vector<Cell*> get_neighbors();
  static Cell*** create_matrix(int height, int width);

  protected:
    bool impassable;
    bool slow;
    bool busy;
    const int y;
    const int x;
    
    Cell* top;
    Cell* bottom;
    Cell* right;
    Cell* left;
  
  friend class CellObject;
  friend class MovableCellObject;
};
#endif //CELL_H
