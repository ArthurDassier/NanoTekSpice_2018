##
## EPITECH PROJECT, 2017
## my_printf
## File description:
## unit_test_makefile
##

CXX	=	g++ -std=c++11

RM	=	rm -f

SRC_DIR	=	../srcs/

SRC_TEST =	ut_test.cpp

OBJ	=	$(SRC_TEST:.cpp=.o)

CXXFLAGS	=	-lcriterion --coverage

CPPFLAGS=	-I../includes/

LDFLAGS	=	-lcriterion --coverage -lgcov

NAME	=	nanotek

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -c $(SRC_DIR)/test.cpp
	$(CXX) -o $(NAME) $(OBJ) test.o $(LDFLAGS)
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *gc*
	$(RM) $(SRC_DIR)*gc*

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	fclean all re clean
