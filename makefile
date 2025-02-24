CC := g++
CFLAGS := -Wall -std=c++11
TARGET := build/chip8

SRC_DIR := src/
SRC_FILES := $(wildcard $(SRC_DIR)*.cpp)
HEADER_FILES := $(wildcard $(SRC_DIR)/include/*.h)

ifeq ($(OS), Windows_NT)
# add build dependencies for windows
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		CFLAGS += -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2
	endif

	ifeq ($(UNAME_S),Linux)
# add build dependencies for linux
	endif
endif

all: $(TARGET)

$(TARGET): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_FILES)

run: $(TARGET)
	@$(TARGET) roms/testrom.ch8

clean: $(TARGET)
	rm $(TARGET)