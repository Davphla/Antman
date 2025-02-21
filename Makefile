##
## EPITECH PROJECT, 2020
## makefile
## File description:
## gcc etc...
##

all:
		@make -C ./lib/my
		@make -C ./antman
		@make -C ./giantman

clean:
		@make clean -C ./lib/my
		@make clean -C ./antman
		@make clean -C  ./giantman

fclean:
		@make fclean -C  ./lib/my
		@make fclean -C ./antman
		@make fclean -C ./giantman

re: fclean all