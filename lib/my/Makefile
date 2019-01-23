##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## can create lib, init the repo folder
##

SRC	=	*.c

NAME	=	libmy.a

INCLUDE_PATH	=	../../include/

TESTS_PATH	=	../../tests/

BONUS_PATH	=	../../bonus/

all:	$(NAME)

init:
	mkdir $(INCLUDE_PATH)
	mkdir $(BONUS_PATH)
	mkdir $(TESTS_PATH)

clean:
	rm -f *.o

copyh:
	cp my.h $(INCLUDE_PATH)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) *.o
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:		fclean all
