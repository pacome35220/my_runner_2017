##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefine
##

SRC	=	my_strlen.c	\
		my_putchar.c	\
		my_putstr.c	\
		concat.c

INC_DIR	=	../include

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -I $(INC_DIR)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
