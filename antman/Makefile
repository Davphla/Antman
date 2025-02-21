##
## EPITECH PROJECT, 2020
## makefile
## File description:
## gcc etc...
##

CFLAGS = -I../include -Wall -Wextra -g3

MY_LIBS = -L../lib -lmy

SRC	=	antman.c \
		compress.c \
		str_to_word_array.c \
		clean_duplicate.c \
		strcont.c \
		image.c \
		style.c \
		huffman.c \
		b_tree.c \
		structures.c \

OBJ		=	$(SRC:.c=.o)

NAME	=	antman


all:	 $(NAME)

$(NAME): $(OBJ)
		gcc $(OBJ) -o $(NAME) $(MY_LIBS)

force:
		gcc $(OBJ) -o $(NAME) $(MY_LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all