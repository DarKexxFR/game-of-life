# Compiler and Flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c99 -Iinclude
LDFLAGS = -lncurses

# Project structure
SRC     = src/main.c src/logic.c
OBJ     = $(SRC:.c=.o)
TARGET  = game_of_life

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
