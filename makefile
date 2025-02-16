CC := g++
CFLAGS := -Wall
TARGET := build/chip8

SRC_DIR := src/
SRC_FILES := *.cpp

C_FILES := $(addprefix $(SRC_DIR), $(SRC_FILES))

all: $(TARGET)

$(TARGET): $(MAIN)
	$(CC) $(CFLAGS) -o $(TARGET) $(C_FILES)

clean: $(TARGET)
	rm $(TARGET)