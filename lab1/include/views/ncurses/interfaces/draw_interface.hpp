#ifndef DRAW_INTERFACE_H
#define DRAW_INTERFACE_H

class IDraw{
  public:
    virtual void invalidate() = 0;
    virtual void check_size() = 0;
};

#endif //DRAW_INTERFACE_H