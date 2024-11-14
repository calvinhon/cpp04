NAME = abstractClass
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -Iinclude
SRCS_DIR = src
INCL_DIR = include
SRCS = $(wildcard $(SRCS_DIR)/*.cpp)
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