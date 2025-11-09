#ifndef CELL_H
#define CELL_H

#include <string>

class Cell{
  public:
    Cell();
    virtual ~Cell();
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    virtual std::string view();
    bool is_impassable();
    bool is_slow();
    Cell* get_top();
    Cell* get_bottom();
    Cell* get_right();
    Cell* get_left();
  static Cell*** create_matrix(int height, int width);
  protected:
    bool impassable;
    bool slow;

    Cell* top;
    Cell* bottom;
    Cell* right;
    Cell* left;
};
#endif //CELL_H
