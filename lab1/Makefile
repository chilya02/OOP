EXECUTABLE = game

CC = g++
CXX_FLAGS = -Wall -Wextra -std=c++20
CFLAGS = -c

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

NCURSES_DIR = ncurses
CELLS_DIR = cells
CELL_OBJ_DIR = cell_objects
CONTROLLERS_DIR = controllers
COMMON_DIR = common

COMMON = game_process.o abstract_iowrapper.o game.o		
	
NCURSES = game_draw.o iowrapper.o command_controller.o 	\
	view_controller.o abs_drawer.o progress_draw.o

CELLS = cell.o impassable_cell.o slow_cell.o game_field.o

CONTROLLERS = enemy_building_controller.o \
	player_controller.o enemies_controller.o

CELL_OBJECTS = cell_obj.o movable_cell_obj.o \
	player.o entity.o enemy_building.o  enemy.o

ENTRY = main.o

OBJECTS = $(addprefix $(OBJ_DIR)/,\
	$(COMMON) $(NCURSES) $(CELLS)		\
	$(CONTROLLERS) $(CELL_OBJECTS)	\
	$(ENTRY)) 

LIB = -lncurses

all: $(OBJ_DIR) $(EXECUTABLE) 

run: all
	./$(EXECUTABLE)

test: all
	./$(EXECUTABLE) < test_data

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXX_FLAGS) $(LIB) $^ -o $(EXECUTABLE)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp	
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(NCURSES_DIR)/%.cpp $(INC_DIR)/$(NCURSES_DIR)/%.hpp
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(CELL_OBJ_DIR)/%.cpp $(INC_DIR)/$(CELL_OBJ_DIR)/%.hpp
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(CELLS_DIR)/%.cpp $(INC_DIR)/$(CELLS_DIR)/%.hpp
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(CONTROLLERS_DIR)/%.cpp $(INC_DIR)/$(CONTROLLERS_DIR)/%.hpp
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(COMMON_DIR)/%.cpp $(INC_DIR)/$(COMMON_DIR)/%.hpp
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

#$(OBJ_DIR)/game_field.o: $(addprefix $(INC_DIR)/, cell.hpp impassable_cell.hpp slow_cell.hpp)


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f game
