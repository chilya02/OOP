#include "../../include/controllers/app_controller.hpp"
#include "../../include/common/serializer.hpp"

AppController::AppController(App* app, IOWrapperInterface* wrapper)
:AppController(app, wrapper->get_command(), wrapper->get_view()){
  
}

AppController::AppController(App* app, CommandInterface* controller, ViewInterface* view)
: app(app), view(view), controller(controller){
  if (app->state == AppState::Play){
    this->process = new GameProcess(app->get_game());
    process->start();
  }
  this->load_menu_controller = new MenuController(app->load_menu, true);
  this->quit_menu_controller = new MenuController(app->quit_menu, true);
  this->game_over_menu_controller = new MenuController(app->game_over_menu, true);
  this->view->invalidate();
  loop();
}

bool AppController::handle_load(Command command){
  if (command == Command::Ok){
    switch (this->app->load_menu->get_selected_item()){
      case LoadMenuItems::Load:
        this->app->game = this->app->loader->load();
        this->process = new GameProcess(app->get_game());
        process->start();
        this->app->state = AppState::Play;
        break;
      case LoadMenuItems::NewGame:
        this->app->game = new Game();
        this->process = new GameProcess(app->get_game());
        process->start();
        this->app->state = AppState::Play;
        break;
      case LoadMenuItems::Exit:
        this->app->state = AppState::Exit;
        break;
      default:
        break;
    }
    return true;
  }
  return this->load_menu_controller->handle_command(command);
}

bool AppController::handle_game_over(Command command){
  if (command == Command::Ok){
    switch (this->app->game_over_menu->get_selected_item()){
      case GameOverMenuItems::NewGame:
        if (this->process){
          delete this->process;
        }  
        if (this->app->game){
          delete this->app->game;
        }
        this->app->game = new Game();
        this->process = new GameProcess(app->get_game());
        this->process->start();
        this->app->state = AppState::Play;
        break;
      case GameOverMenuItems::Exit:
        this->app->state = AppState::Exit;
        break;
      default:
        break;
    }
    return true;
  }
  return this->game_over_menu_controller->handle_command(command);
}

bool AppController::handle_quit(Command command){
  if (command == Command::Ok){
    switch (this->app->quit_menu->get_selected_item()){
      case QuitMenuItems::Continue:
        this->app->state = AppState::Play;
        break;
      case QuitMenuItems::Save:
        app->serializer = new Serializer(this->app->game);
        app->serializer->save();
        delete app->serializer;
        break;

      case QuitMenuItems::Exit:
        this->app->state = AppState::Exit;
        break;
      default:
        break;
    }
    return true;
  }
  return this->quit_menu_controller->handle_command(command);
}

void AppController::loop(){
  bool flag = false;
  Command command;
  this->view->invalidate();
  while (this->app->get_state() != AppState::Exit){
    flag = false;
    command = controller->get_command();
    view->check_size();

    if (command == Command::Quit){
      switch (this->app->get_state()){
        case AppState::Play:
          app->state = AppState::Quit;
          flag = true;
          break;
        case AppState::Load:
        case AppState::Quit:
        case AppState::GameOver:
          this->app->state = AppState::Exit;
          break;
      }
      
    }
    switch (this->app->get_state()){
      case AppState::Load:
        flag = this->handle_load(command);
        break;
      case AppState::Play:
        flag = this->process->handle_command(command);
        if (this->app->game->player->get_HP() == 0){
          this->app->state = AppState::GameOver;
        }
        break;
      case AppState::GameOver:
        flag = this->handle_game_over(command);
        break;
      case AppState::Quit:
        flag = flag || this->handle_quit(command); 
        break;
      default:
        break;
    }
    if (flag && app->state != AppState::Exit){
      this->view->invalidate();
    }
  }
}