EXECUTABLE = game

CC = g++
CXX_FLAGS = -Wall -Wextra -std=c++20
CFLAGS = -c

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

COMMON = 				abstract_iowrapper.o \
								serializer.o \
								loader.o 

CONTROLLERS = 	movable_damage_controller.o \
								enemy_building_controller.o \
								spells_hand_controller.o \
								movable_controller.o \
								enemies_controller.o \
								player_controller.o \
								weapon_controller.o	\
								menu_controller.o \
								command_handler.o \
								app_controller.o \
								game_process.o

NCURSES =		 		command_controller.o \
								abs_game_drawer.o \
								progress_draw.o \
								abs_drawer.o \
								field_draw.o \
								menu_draw.o \
								game_draw.o \
								iowrapper.o \
								hand_draw.o	\
								view.o

SPELLS =	 			direct_damage.o	\
								spells_hand.o \
								area_damage.o 

CELLS = 				impassable_cell.o \
								game_field.o \
								slow_cell.o \
								cell.o 

CARDS =		 			movable_damage_card.o \
								direct_damage_card.o \
								area_damage_card.o \
								abstract_card.o

CELL_OBJECTS = 	movable_physical_cell_obj.o \
								physical_cell_obj.o \
								movable_cell_obj.o \
								enemy_building.o \
								movable_damage.o \
								cell_obj.o \
								player.o \
								entity.o \
								enemy.o	

MODELS = 				$(CELL_OBJECTS) \
								$(SPELLS) \
								$(CELLS) \
								$(CARDS) \
								load_menu.o \
								quit_menu.o \
								weapon.o \
								game.o	\
								app.o

ENTRY =					main.o

OBJECTS = 			$(addprefix $(OBJ_DIR)/,\
								$(CONTROLLERS) \
								$(NCURSES) \
								$(COMMON) \
								$(MODELS) \
								$(ENTRY) )

LIB = -lncurses

COMPILE = $(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

all: $(OBJ_DIR) $(EXECUTABLE) 

da:
	VIEW_DIR = ncurses
	echo $(VIEW_DIR)

run: all
	./$(EXECUTABLE)

test: all
	./$(EXECUTABLE) < test_data

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXX_FLAGS) $^ -o $(EXECUTABLE) $(LIB)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(COMPILE)

$(OBJ_DIR)/%.o: %.cpp %.hpp
	$(COMPILE)

vpath %.cpp $(SRC_DIR)/common $(SRC_DIR)/common/abstract $(SRC_DIR)/common/ncurses
vpath %.cpp $(SRC_DIR)/controllers/abstract $(SRC_DIR)/controllers
vpath %.cpp $(SRC_DIR)/inputs $(SRC_DIR)/inputs/ncurses
vpath %.cpp $(SRC_DIR)/models $(SRC_DIR)/models/cards $(SRC_DIR)/models/cards/abstract
vpath %.cpp $(SRC_DIR)/models/cell_objects $(SRC_DIR)/models/cell_objects/abstract
vpath %.cpp $(SRC_DIR)/models/cells $(SRC_DIR)/models/spells $(SRC_DIR)/models/spells/abstract
vpath %.cpp $(SRC_DIR)/models/weapon $(SRC_DIR)/views $(SRC_DIR)/views/ncurses $(SRC_DIR)/views/ncurses/abstract
vpath %.cpp $(SRC_DIR)/models/menus

vpath %.hpp $(INC_DIR)/common $(INC_DIR)/common/abstract $(INC_DIR)/common/ncurses
vpath %.hpp $(INC_DIR)/controllers/abstract $(INC_DIR)/controllers
vpath %.hpp $(INC_DIR)/inputs $(INC_DIR)/inputs/ncurses
vpath %.hpp $(INC_DIR)/models $(INC_DIR)/models/cards $(INC_DIR)/models/cards/abstract
vpath %.hpp $(INC_DIR)/models/cell_objects $(INC_DIR)/models/cell_objects/abstract
vpath %.hpp $(INC_DIR)/models/cells $(INC_DIR)/models/spells $(INC_DIR)/models/spells/abstract
vpath %.hpp $(INC_DIR)/models/weapon $(INC_DIR)/views $(INC_DIR)/views/ncurses $(INC_DIR)/views/ncurses/abstract
vpath %.hpp $(INC_DIR)/models/menus

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f game

.PHONY : all clean run
