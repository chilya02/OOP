#ifndef VIEW_INTERFACE_H
#define VIEW_INTERFACE_H

class ViewInterface{
  public:
    virtual ~ViewInterface(){};
    virtual void invalidate() = 0;
    virtual void check_size() = 0;
};

#endif
