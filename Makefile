##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

CC			=	g++

NAME		=	nanotekspice

TESTS_NAME	=	unit_tests

SRC			=

OBJ			=	$(SRC:.cpp=.o)

TESTS_SRC	=	$(filter-out src/Main.cpp, $(SRC))	\
				tests/test_or_gate.cpp				\
				tests/test_clock.cpp				\
				tests/test_bad.cpp					\
				tests/test_no_argument.cpp

CPPFLAGS	=	-std=c++20 -W -Wall -Wextra -Werror -Wpedantic -I./include/

TESTS_FLAGS	=	-lcriterion --coverage

# Compilation rules

all:
	@$(MAKE) -s $(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

debug:
	@$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) -g

# Run rules

run:	re
	@./$(NAME) $(FILE)

vrun:	debug
	@valgrind --leak-check=full ./$(NAME) $(FILE)

# Tests and coverage rules

tests_run:	fclean $(TESTS_NAME)
	@./$(TESTS_NAME)

$(TESTS_NAME):
	@$(CC) -o $(TESTS_NAME) $(TESTS_SRC) $(CPPFLAGS) $(TESTS_FLAGS)

cov:
	@gcovr --exclude tests -u

covb:
	@gcovr --exclude tests -ub

# Clean rules

clean:
	@rm -f $(OBJ)
	@rm -f *.gcda
	@rm -f *.gcno

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(TESTS_NAME)

re:	fclean all
