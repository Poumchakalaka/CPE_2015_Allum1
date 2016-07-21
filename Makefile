##
## Makefile for Makefile in /home/henry_g/rendu
## 
## Made by Clément Henry
## Login   <henry_g@epitech.net>
## 
## Started on  Fri Dec  5 22:21:16 2014 Clément Henry
## Last update Sun Feb 21 21:19:04 2016 spare spare
##

SRC=	main.c \
	needs.c \
	epur_str.c \
	ia_2.c \
	3_ia.c \
	game.c \
	2_game.c \
	get_next_line.c \
	ia.c \
	init.c \
	allum1.c 

NAME=	allum1

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	cc $(OBJ) -lncurses  -o $(NAME) $(LIB)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all
