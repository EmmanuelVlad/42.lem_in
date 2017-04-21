# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evlad <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 16:48:29 by evlad             #+#    #+#              #
#    Updated: 2017/04/21 20:09:38 by evlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC = src

LIST = main.c \

PATH = $(OBJ_PATH)$(NAME)/

FILES = $(LIST:%=./$(SRC)/%)

OBJ = $(LIST:%.c=%.o)

PROGRAM = $(OBJ:%=$(PATH)%)

LIBFT = ./libft/libft.a

OBJ_PATH = ./obj/

LIBFT_INC = -L ./libft/ -lft

FLAGS = -Wextra -Werror -Wall

OK = "\033[1;32m[OK]\033[0m"

$(PATH)%.o: $(FILES) ./$(SRC)/$(NAME).h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(PATH)
	@gcc $(FLAGS) -c ./$(SRC)/$(@F:%.o=%.c) -o $(@F:%=$(OBJ_PATH)$(NAME)/%)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo -n '-> Compiling LIBFT .'
	@make -C ./libft/
	@echo -n '..			'
	@echo $(OK)

$(NAME): $(PROGRAM)
	@echo -n '-> Compiling  LEM_IN ..'
	@gcc -o $(NAME) $(OBJ:%=$(OBJ_PATH)$(NAME)/%) $(LIBFT_INC)
	@echo -n '.		'
	@echo $(OK)

clean:
	@echo -n '-> Deleting object files ..'
	@/bin/rm -rf $(OBJ_PATH)
	@echo -n '.		'
	@make -C ./libft/ clean
	@echo $(OK)

fclean: clean
	@echo -n '-> Deleting executable files ..'
	@/bin/rm -f $(NAME)
	@echo -n '.	'
	@make -C ./libft/ fclean
	@echo $(OK)

re: fclean all

.PHONY: clean fclean re