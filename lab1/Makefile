EXECUTABLE = game
CC = g++
CXX_FLAGS = -Wall -Wextra -std=c++20
CFLAGS = -c
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include
CUR_DIR = ncurses
OBJ = game_field.o main.o cell.o impassable_cell.o 	\
	slow_cell.o game_process.o player.o entity.o    	\
	enemy_build.o player_controller.o enemy.o					\
	cell_obj.o movable_cell_obj.o game.o							\
	enemies_controller.o abstract_iowrapper.o

CUR = game_draw.o iowrapper.o command_controller.o view_controller.o

LIB = -lncurses

all: $(OBJ_DIR) $(EXECUTABLE) 

run: all
	./$(EXECUTABLE)

test: all
	./$(EXECUTABLE) < test_data

$(EXECUTABLE): $(addprefix $(OBJ_DIR)/, $(OBJ) $(CUR))
	$(CC) $(CXX_FLAGS) $(LIB) $^ -o $(EXECUTABLE)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/game_process.hpp	
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(CUR_DIR)/%.cpp $(INC_DIR)/$(CUR_DIR)/%.hpp
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(CC) $(CFLAGS) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/game_field.o: $(addprefix $(INC_DIR)/, cell.hpp impassable_cell.hpp slow_cell.hpp)


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f game
