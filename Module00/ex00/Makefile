NAME = Devide_and_conquer

SRC = main.cpp \
		CustomerAccountSystem.cpp \
		BankingSystem.cpp \

OBJ = $(SRC:.cpp=.o)

CC = clang++

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -std=c++11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re