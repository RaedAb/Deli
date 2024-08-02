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

# OpenCV flags
OPENCV_CFLAGS = $(shell pkg-config --cflags opencv4)
OPENCV_LDFLAGS = $(shell pkg-config --libs opencv4)

# Targets
app: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o app $(OBJ_FILES) $(OPENCV_LDFLAGS)

test: $(OBJ_FILES_NO_MAIN) $(TEST_FILE)
	$(CXX) $(CXXFLAGS) -o test $(OBJ_FILES_NO_MAIN) $(TEST_FILE) $(OPENCV_LDFLAGS)

# Rule for compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@if [ $< = $(SRC_DIR)/Receipt.cpp ]; then \
		$(CXX) $(CXXFLAGS) $(OPENCV_CFLAGS) -c $< -o $@; \
	else \
		$(CXX) $(CXXFLAGS) -c $< -o $@; \
	fi

# Clean up build files
clean:
	rm -f $(OBJ_DIR)/*.o app test
	rm -rf $(OBJ_DIR)

.PHONY: app test clean