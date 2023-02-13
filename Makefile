#-*MAKEFILE*-

# target:   dependencies
#           action


CC			= cc
CFLAGS		= -Wall -Wextra -Werror

NAME		= gnl.a

MAND		= get_next_line.c get_next_line_utils.c

OBJ_MAND	= $(MAND:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ_MAND)
	ar rc $(NAME) $(OBJ_MAND)

clean:
	rm -rf $(OBJ_MAND)

fclean: clean
	rm -rf $(NAME)

re: fclean all