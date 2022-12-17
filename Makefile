NAME = ft
NAME2 = std
SRCS = main.cpp main_std.cpp
CXX = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
OBJS = $(SRCS:.cpp=.o)
INC = bidirectionnal_iterator.hpp enable_if.hpp is_integral.hpp iterator_traits.hpp lexicographical_compare.hpp make_pair.hpp pair.hpp map.hpp random_access.hpp RBreverse_iterator.hpp red_black_tree.hpp reverse_iterator.hpp stack.hpp vector.hpp

%.o: %.cpp $(INC)
	$(CXX) $(FLAGS) -I./ -c $< -o $@

all: $(NAME) $(NAME2)

$(NAME): main.o
	$(CXX) $(FLAGS) main.o -o $(NAME)

$(NAME2): main_std.o
	$(CXX) $(FLAGS) main_std.o -o $(NAME2)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re