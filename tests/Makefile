##
## EPITECH PROJECT, 2017
## my_printf
## File description:
## unit_test_makefile
##

CC	=	g++

RM	=	rm -f

SRC_DIR	=	../srcs/

SRC_TEST=	ut_test.cpp\

OBJ	=	$(SRC_TEST:.cpp=.o)

CFLAGS	=	-lcriterion --coverage

CPPFLAGS=	-I../includes/

LDFLAGS	=	-lcriterion --coverage

NAME	=	my_malloc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *gc*
	$(RM) $(SRC_DIR)*gc*

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	fclean all re clean
