##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## makefile
##

CC =		gcc

LDFlags +=	-lncurses

NAME =		my_sokoban

SRC =		main.c \
			init_map.c \
			basic_error_case.c \
			init_var.c \
			find_position.c \
			check_win_or_lose.c \
			cond_init_map.c \
			my_strcpy.c

OBJ =		$(SRC:.c=.o)

all :		$(NAME)

$(NAME) :	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(LDFlags) -g3

clean :
			rm -rf $(OBJ)

fclean :	clean
			rm -rf $(NAME)

re :		fclean all
