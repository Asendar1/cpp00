SRCS_FILES = main.cpp Contact.cpp PhoneBook.cpp
SRCS = $(addprefix srcs/, $(SRCS_FILES))

OBJS = $(SRCS:.cpp=.o)

NAME = nannys_phone

CXX = c++ -Wall -Wextra -Werror -std=c++98
CXXFLAGS = -I incs

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re


