RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m

NAME = Data_base2024
SRCS = main.c \
	   ask_consult.c \
	   ask_utils.c \
	   init_calender.c \
	   init_employee.c \
	   modules.c \
	   safe_functions.c \
	   extras.c \
	   shedules.c \
	   utils.c \
	   shedules_utils.c \
	   logo.c \
	   treat_file.c

CC = gcc
FLAGS = -Wall -Wextra -Werror -MMD
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
SILENCE = --no-print-directory

all: $(NAME)

%.o:%.c Makefile lib.h
	@echo "$(RED) [OK] $(RESET) $(CYAN)$(BOLD) $<$(RESET)"
	@$(CC) $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS) lib.h Makefile
	@echo "$(WHITE) $(NAME) $(RESET) $(GREEN) [OK] $(RESET)"
	@echo "$(RED) -Todo ha sido compilado! $(RESET)"
	@$(CC) $(OBJS) -o $(NAME) -lncurses

clean:
	@echo "$(RED) Eliminando .o  ... $(RESET)"
	@rm -f $(OBJS) $(DEPS)
	@echo "$(RED) [CleanOK]  $(RESET)"

fclean: clean
	@echo "$(RED) Eliminando ... $(RESET)"
	@rm -f $(NAME)
	@echo "$(RED) [FcleanOK]  $(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
