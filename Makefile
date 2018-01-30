##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefine
##

SRC	=	$(SRC_DIR)main.c	\
		$(SRC_DIR)fopen_file.c	\
		$(SRC_DIR)parsing.c	\
		$(SRC_DIR)h_option.c	\
		$(SRC_DIR)create_window.c	\
		$(SRC_DIR)check_event.c	\
		$(SRC_DIR)init_game_object.c	\
		$(SRC_DIR)create_object.c	\
		$(SRC_DIR)parallax_back.c	\
		$(SRC_DIR)move_bird.c	\
		$(SRC_DIR)print_score.c	\
		$(SRC_DIR)draw_all.c	\
		$(SRC_DIR)destroy_free.c

SRC_DIR	=	src/

LIB_DIR	=	lib/

INC_DIR	=	include/

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -I $(INC_DIR) -g

LDFLAGS	=	-L $(LIB_DIR) -lmy -lc_graph_prog

NAME	=	my_runner

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
