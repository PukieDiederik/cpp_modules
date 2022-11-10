# Colors
BLACK			= \033[0;30m
RED				= \033[0;31m
GREEN			= \033[0;32m
ORANGE			= \033[0;33m
BLUE			= \033[0;34m
PURPLE			= \033[0;35m
CYAN			= \033[0;36m
GRAY			= \033[0;37m
WHITE			= \033[0;38m
RESET			= \033[0m

# Variables
SRCS		= main.cpp Zombie.cpp zombieHorde.cpp
OBJS		= $(SRCS:.cpp=.o)
INCS		= -I $(INCLUDE_DIR)

INCLUDE_DIR	= .

NAME		= zombies

CXXFLAGS	= $(INCS) -Wall -Werror -Wextra -pedantic -Ofast -std=c++98 -Wsign-conversion -g -fsanitize=address

# Commands
CXX			= c++
ECHO		= echo -e
RM			= rm -rf

## Functions
all: $(NAME)

%.o : %.cpp
	@$(ECHO) "$(GREEN)>>> Compiling $(WHITE)$< $(GREEN)-> $(WHITE)$@$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(ECHO) "$(GREEN)>>>>> $(WHITE)linking $(GREEN)<<<<<$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(ECHO) "$(RED)>>>>>$(WHITE) Deleting object files $(RED)<<<<<$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@$(ECHO) "$(RED)>>>>> $(WHITE)Deleting executable $(RED)<<<<<$(RESET)"
	@$(RM) $(NAME)

re: fclean all
