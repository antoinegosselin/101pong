##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/pong.c 	\
		src/events.c 		\
		src/back.c			\
		src/ball.c			\
		src/menu.c			\
		src/music.c			\
		src/options.c 		\
		src/menu_event.c	\
		src/level.c			\
		src/speed.c			\
		src/score.c			\
		src/raquette.c

NAME	=	pong

OBJ	=	$(SRC:.c=.o)

LIB_PATH	=	../lib/my/

LIB_NAME	=	my

TEST_PATH 	= 	./tests/

CFLAGS	=	-W -Wall -I ../include/ -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME) clean

$(NAME):	$(OBJ)
	make -C ../lib/my/
	gcc -o $(NAME) $(OBJ) -L$(LIB_PATH) -l$(LIB_NAME) $(CFLAGS)

clean:
	make clean -C ../lib/my/
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB_PATH)libmy.a
	rm -f unit_test*

re:	fclean all

tests_run: 
	