#include "../../include/common/abstract_iowrapper.hpp"

CommandInterface* IOWrapper::get_command(){
  return this->command;
}

ViewInterface* IOWrapper::get_view(){
  return this->view;
}
