##
## EPITECH PROJECT, 2025
## gomoku
## File description:
## gomoku
##

SRC	=	src/main.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	game-jam

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-std=c++17 -I ./include

++	?=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
			$(++) -o $(NAME) $(OBJ) -lraylib

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

debug:	CPPFLAGS += -g3
debug:	re

.PHONY:	all clean fclean re debug