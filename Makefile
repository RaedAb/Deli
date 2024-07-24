# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Directories
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

# Files
MAIN = $(SRC_DIR)/main.cpp
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
OBJ_FILES_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o, $(OBJ_FILES))

# Test files
TEST_FILE = $(TEST_DIR)/test.cpp

# Targets
app: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o app $(OBJ_FILES)

test: $(OBJ_FILES_NO_MAIN) $(TEST_FILE)
	$(CXX) $(CXXFLAGS) -o test $(OBJ_FILES_NO_MAIN) $(TEST_FILE)

# Rule for compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_DIR)/*.o app test
	rm -rf $(OBJ_DIR)

.PHONY: app test clean