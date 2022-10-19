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
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
INCLUDES	= $(INCLUDE_DIR)

INCLUDE_DIR	= .

NAME		= megaphone

CFLAGS		= -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address

# Commands
CC			= g++
ECHO		= echo -e
RM			= rm -rf

## Functions
%.o : %.cpp
	@$(ECHO) "$(GREEN)>>> Compiling $(WHITE)$< $(GREEN)-> $(WHITE)$@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(ECHO) "$(GREEN)>>>>> $(WHITE)linking $(GREEN)<<<<<$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(ECHO) "$(RED)>>>>>$(WHITE) Deleting object files $(RED)<<<<<$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@$(ECHO) "$(RED)>>>>> $(WHITE)Deleting executable $(RED)<<<<<$(RESET)"
	@$(RM) $(NAME)

re: fclean all
