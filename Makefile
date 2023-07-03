##
## EPITECH PROJECT, 2023
## B-PSU-200-LIL-2-1-minishell2-nicolas1.nguyen
## File description:
## Makefile
##

SRC = 	main.c 						\
		palindrome.c 				\
		palindrome2.c 				\
		tools.c 					\

OBJ = $(SRC:.c=.o)

CFLAGS += -Werror -Wextra -I./include

CSFML = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

NCURSES = -lncurses

GCC_TEST =		gcc requirement.c tests/tests.c tests/base_requirement.c \
				-o unit_tests -lcriterion --coverage

NAME = palindrome

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

all:     $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

re:	fclean all

tests_run:
	$(GCC_TEST)
	echo
	./unit_tests
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests

.PHONY: all clean fclean re
