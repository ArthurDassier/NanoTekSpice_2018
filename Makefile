##
## EPITECH PROJECT, 2018
## project name here
## File description:
## Makefile
##

INCLUDE_DIR=	./includes/

TESTS_DIR=	./tests/

CXX	=	g++ -std=c++11

RM	=	rm -f

SRC_DIR	=	srcs/

SRC	=	$(SRC_DIR)main.cpp\
		$(SRC_DIR)test.cpp\

CXXFLAGS	=	-Wall -Wextra -Werror

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
<<<<<<< HEAD
<<<<<<< HEAD
	$(CC) -o $(NAME) $(OBJ)
=======
	$(CXX) -o $(NAME) $(OBJ)
>>>>>>> 239c59194579ca7e4271a61f0cc38c09a3ddbd3f
=======
	$(CXX) -o $(NAME) $(OBJ)
>>>>>>> 239c59194579ca7e4271a61f0cc38c09a3ddbd3f

clean:
	$(RM) $(OBJ)

fclean:	clean ut_clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:
	fclean all re clean $(NAME)
