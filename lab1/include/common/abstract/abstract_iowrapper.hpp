#include "../interfaces/iowrapper_interface.hpp"

class IOWrapper:public IOWrapperInterface{

  public:
    CommandInterface* get_command() final;
    ViewInterface* get_view() final;
  
  protected:
    CommandInterface* command;
    ViewInterface* view;
};