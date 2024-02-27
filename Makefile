##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

CC			=	g++

NAME		=	nanotekspice

TESTS_NAME	=	unit_tests

SRC			=	src/Main.cpp										\
				src/NanoTekSpice.cpp								\
				src/Utilities/Utilities.cpp							\
				src/Parsing/Config/Config.cpp						\
				src/Circuit/Circuit.cpp								\
				src/Shell/Shell.cpp									\
				src/Components/AComponent.cpp						\
				src/Components/Elementary/And/ComponentAnd.cpp		\
				src/Components/Elementary/Not/ComponentNot.cpp		\
				src/Components/Special/False/ComponentFalse.cpp		\
				src/Components/Special/True/ComponentTrue.cpp		\
				src/Components/Elementary/Or/ComponentOr.cpp		\
				src/Components/Elementary/Xor/ComponentXor.cpp		\
				src/Components/Special/Input/ComponentInput.cpp		\
				src/Components/Special/Output/ComponentOutput.cpp	\
				src/Components/Special/Clock/ComponentClock.cpp		\
				src/Components/Gates/4001/Component4001.cpp			\
				src/Components/Gates/4011/Component4011.cpp			\
				src/Components/Gates/4030/Component4030.cpp			\
				src/Components/Gates/4069/Component4069.cpp			\
				src/Components/Gates/4071/Component4071.cpp			\
				src/Components/Gates/4081/Component4081.cpp			\
				src/Components/Advanced/4008/Component4008.cpp		\
				src/Components/Advanced/4013/Component4013.cpp		\
				src/Components/Factory/ComponentsFactory.cpp

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
