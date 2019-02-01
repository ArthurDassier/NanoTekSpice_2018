##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	nano

CXX	=	g++ -std=c++11

MAKE	=	/usr/bin/make

SRC_DIR	=	./srcs

BUILTINS	=$(SRC_DIR)/builtins

EXTRA		=$(SRC_DIR)/extra

HISTORY_DIR =	$(SRC_DIR)/history/

VAR_DIR	=	$(SRC_DIR)/variables/

LIB_DIR	=	./lib/my

UT_DIR	=	./tests

LIB_DIR	=	./lib/my

EXE	=	$(SRC_DIR)/Components/Component_4001.cpp	\
		$(SRC_DIR)/Components/Component_4008.cpp		\
		$(SRC_DIR)/SpecialComponents/True.cpp		\
		$(SRC_DIR)/SpecialComponents/False.cpp		\

OBJ	=	$(EXE:.cpp=.o)

UT 	= 	$(UT_DIR)/Components/tests_Component_4001.cpp	\
		$(UT_DIR)/Components/tests_Component_4008.cpp	\

UT2	=	$(SRC_DIR)/Components/Component_4001.cpp		\
	$(SRC_DIR)/Components/Component_4008.cpp		\
		$(SRC_DIR)/SpecialComponents/True.cpp			\
		$(SRC_DIR)/SpecialComponents/False.cpp			\

RM	=	rm -f

CXXFLAGS	=	-Wall -Wextra

CPPFLAGS=	-I./includes/ -I./srcs/Components -I./srcs/SpecialComponents

LDFLAGS	=

UT_FLAGS=	-lcriterion --coverage

INCLUDE	=	-I./includes -I./srcs/Components -I./srcs/SpecialComponents


all:		$(NAME)

$(NAME):
		g++ $(INCLUDE) $(EXE) -o $(NAME)

tests_run:
		$(CXX) $(INCLUDE) -o UT $(UT) $(UT2) -lcriterion -coverage
		./UT

clean:
		$(RM) $(OBJ)

ut_clean:
		rm *.gc*
		rm UT

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
