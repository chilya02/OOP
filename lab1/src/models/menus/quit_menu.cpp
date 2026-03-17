#include "../../../include/models/menus/quit_menu.hpp"


QuitMenu::QuitMenu():Menu<QuitMenuItems>(){
  this->add_item(QuitMenuItems::Continue, "Continue");
  this->add_item(QuitMenuItems::Save, "Save");
  this->add_item(QuitMenuItems::Exit, "Exit");
} 