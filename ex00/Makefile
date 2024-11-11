NAME = polymorphism
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp animal.cpp dog.cpp cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.phony: all clean fclean re