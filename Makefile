# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I./src
LDFLAGS = -fuse-ld=mold  # mold linker

# Directories
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

# Source and output files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/get_line.c $(SRC_DIR)/copy_line.c $(SRC_DIR)/trim_line.c $(SRC_DIR)/revert_line.c
OBJS = $(SRCS:.c=.o)
EXEC = $(BUILD_DIR)/main

# Test files
TESTS = $(TEST_DIR)/test_get_line.c $(TEST_DIR)/test_copy_line.c $(TEST_DIR)/test_trim_line.c $(TEST_DIR)/test_revert_line.c

# Default target
all: $(EXEC)

# Build the main executable
$(EXEC): $(OBJS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run tests
test: $(TESTS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_get_line $(TEST_DIR)/test_get_line.c $(SRC_DIR)/get_line.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_copy_line $(TEST_DIR)/test_copy_line.c $(SRC_DIR)/copy_line.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_trim_line $(TEST_DIR)/test_trim_line.c $(SRC_DIR)/trim_line.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_revert_line $(TEST_DIR)/test_revert_line.c $(SRC_DIR)/revert_line.c
	$(BUILD_DIR)/test_get_line
	$(BUILD_DIR)/test_copy_line
	$(BUILD_DIR)/test_trim_line
	$(BUILD_DIR)/test_revert_line

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(SRC_DIR)/*.o