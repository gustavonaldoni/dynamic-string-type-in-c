EXECUTABLE_NAME = main.out
SOURCE_FILE = src/main.c
LIB_FILES = $(wildcard lib/*.c)

CC = gcc
CFLAGS = -Wall -Werror

all:
	$(CC) $(SOURCE_FILE) -o build/$(EXECUTABLE_NAME) $(LIB_FILES) $(CFLAGS) -I./include