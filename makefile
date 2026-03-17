CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23 -I./include
LDFLAGS = -lncursesw
SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.cc $(SRC_DIR)/screen.cc
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/screen.o
TARGET = $(BUILD_DIR)/ncrypt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
