NAME = BSP
SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
CXX = c++
CXXFLAGS = -I. -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re