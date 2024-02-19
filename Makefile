##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

CC			=	g++

NAME		=	nanotekspice

TESTS_NAME	=	unit_tests

SRC			=	src/Main.cpp			\
				src/NanoTekSpice.cpp	\
				src/Components/AComponent.cpp	\
				src/Components/IComponent.cpp	\
				src/Components/Elementary/And/ComponentAnd.cpp	\
				src/Components/Elementary/Not/ComponentNot.cpp	\
				src/Components/Special/False/ComponentFalse.cpp	\
				src/Components/Special/True/ComponentTrue.cpp	\
				src/Components/Elementary/Or/ComponentOr.cpp		\
                src/Components/Elementary/Xor/ComponentXor.cpp	\
                src/Components/Special/Input/ComponentInput.cpp	\
                src/Components/Special/Output/ComponentOutput.cpp	\
                src/Components/Special/Clock/ComponentClock.cpp	\
                src/Components/Gates/4001/Component4001.cpp	\
                src/Components/Gates/4011/Component4011.cpp	\
                src/Components/Gates/4030/Component4030.cpp

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

debug:	fclean
	@$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) -g

re:	fclean all

# Run rules

run:	all
	@./$(NAME)

vrun:	debug
	@valgrind --leak-check=full ./$(NAME)

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
