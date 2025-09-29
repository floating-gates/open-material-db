# Compiler and flags
CC = gcc
CFLAGS =  -Wall -Wextra -O2 
LDFLAGS = -lsqlite3

# Project structure
SRC = src/main.c \
	src/json.c

OBJ = $(SRC:.c=.o)
BIN = open-mat-db

# Default target
all: $(BIN)

# Link object files into final binary
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(LDFLAGS)

# Compile .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -f $(OBJ) $(BIN)

# Run the program
run: $(BIN)
	./$(BIN)
