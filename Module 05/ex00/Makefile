NAME = Bureaucrat
SRC = main.cpp Bureaucrat.cpp
CXX = c++
CXXFLAGS = -I. -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean re