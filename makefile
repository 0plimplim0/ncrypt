CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23 -I./include
LDFLAGS = -lncursesw
SRC_DIR = src
BUILD_DIR = build
SRC_GAME_SCREENS = $(SRC_DIR)/playScreen.cc $(SRC_DIR)/leaderboardScreen.cc
BUILD_GAME_SCREENS = $(BUILD_DIR)/playScreen.o $(BUILD_DIR)/leaderboardScreen.o

SRCS = $(SRC_DIR)/main.cc $(SRC_DIR)/screen.cc $(SRC_DIR)/gamemanager.cc $(SRC_DIR)/cryptogram.cc $(SRC_GAME_SCREENS)
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/screen.o $(BUILD_DIR)/gamemanager.o $(BUILD_DIR)/cryptogram.o $(BUILD_GAME_SCREENS)
TARGET = $(BUILD_DIR)/ncrypt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
