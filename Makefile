##
## EPITECH PROJECT, 2018
## project name here
## File description:
## Makefile
##

INCLUDE_DIR=	./includes/

TESTS_DIR=	./tests/

CC	=	g++

RM	=	rm -f

SRC_DIR	=	srcs/

SRC	=	$(SRC_DIR)main.cpp

CFLAGS	=	-Wall -Wextra -Werror

CPPFLAGS=	-I$(INCLUDE_DIR)

OBJ	=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

all:	$(NAME)

debug:	CFLAGS	+= -g3
debug:	MAKE	+= debug
debug:	all

tests_run:
	$(MAKE) -C $(TESTS_DIR)

ut_clean:
	$(MAKE) fclean -C $(TESTS_DIR)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean ut_clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:
	fclean all re clean $(NAME)
