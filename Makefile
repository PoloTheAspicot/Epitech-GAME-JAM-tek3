##
## EPITECH PROJECT, 2025
## game-jam
## File description:
## game-jam
##

SRC	=	$(addprefix src/, 		\
			main.cpp			\
			TomatoSurvivor.cpp	\
		)

OBJ	=	$(SRC:.cpp=.o)

NAME	=	game-jam

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-std=c++17 -I ./include

CXX	?=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ) -lraylib

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

debug:	CPPFLAGS += -g3
debug:	re

.PHONY:	all clean fclean re debug
