##
## EPITECH PROJECT, 2020
## makefile
## File description:
## gcc etc...
##

CFLAGS = -I../include -Wall -Wextra -g3

MY_LIBS = -L../lib -lmy

SRC	=	giantman.c \
		dictionary.c \
		uncompress.c \
		uncipher_image.c \
		huffman.c \
		b_tree.c \
		gigi.c \

OBJ		=	$(SRC:.c=.o)

NAME	=	giantman


all:	 $(NAME)

$(NAME): $(OBJ)
		gcc $(OBJ) -o $(NAME) $(MY_LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all