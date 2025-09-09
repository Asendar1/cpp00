SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)

NAME = account

CXX = c++ -Wall -Werror -Wextra -std=c++98

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -IAccount.hpp -o $(NAME)

%.o: %.cpp
	$(CXX) -IAccount.hpp -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean