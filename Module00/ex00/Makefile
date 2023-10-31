NAME = ex00

# Compiler: gcc for C program, g++ for C++

CC = g++

# Flags: -Wall -Wextra -Werror for mandatory part

FLAGS = -Wall -Wextra -Werror

# Source files

SRC = ./main.cpp \
		./Bank.cpp

# Object files

OBJ = $(SRC:.cpp=.o)

# Compile

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

# Clean

clean:
	rm -f $(OBJ)

# Fclean

fclean: clean
	rm -f $(NAME)

# Re

re: fclean all

# .PHONY