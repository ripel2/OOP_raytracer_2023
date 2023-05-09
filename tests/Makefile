##
## EPITECH PROJECT, 2023
## OOP_raytracer_2023
## File description:
## Makefile
##

GCC			=	g++
RM			=	-rm

NAME		=	unit_tests

SRC			=	$(wildcard unit_tests_src/*.cpp)
SRC			+=	$(wildcard ../src/shared/*.cpp)

OBJ			=	$(SRC:%.cpp=%.o)

INCLUDES	=	-I../src/shared

CXXFLAGS	=	$(INCLUDES) -Wall -Wextra -Wshadow -Wpedantic -Iinclude
CXXFLAGS	+=	-std=c++17 -O3
CXXFLAGS	+=	-I./src
CXXFLAGS	+=	-lconfig++ -lcriterion 
CXXFLAGS	+=	--coverage -fprofile-arcs -ftest-coverage

all:		$(NAME)

$(NAME):	$(OBJ)
	$(GCC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	find .. -name "*~" -delete -or -name "#*#" -delete
	find .. -name "*.o" -delete
	find .. -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean:		clean
	$(RM) -f $(NAME)

re:		fclean $(NAME)

coverage:	$(NAME)
	./$(NAME)

debug:		CXXFLAGS += -g3
debug:		re

.PHONY:	all clean fclean re
