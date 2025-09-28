# Compiler
CC = c3c
CFLAGS =   

# Libraries
LIBS = sqlite3
LIB_FLAG = -l $(LIBS)

# Sources and target
SRC = src/main.c3
TARGET = open_db_generator

# Default target
all: $(TARGET)

# Build executable
$(TARGET):
	$(CC) compile $(SRC) $(CFLAGS) $(LIB_FLAG)

# Clean
clean:
	rm -f $(TARGET)

.PHONY: all clean
