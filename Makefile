##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/pong.c \
		src/usage.c \
		src/print_res.c \
		src/get_coordinates.c

SRC_TEST_1	=	src/pong.c \
				src/usage.c \
				src/print_res.c \
				src/get_coordinates.c \
				tests/test_pong.c

SRC_TEST_2	=	src/usage.c \
				tests/test_wrong_usage.c

NAME	=	101pong

OBJ	=	$(SRC:.c=.o)

LIB_PATH	=	./lib/my/

LIB_NAME	=	my
UNIT_NAME	=	unit_test

TEST_PATH 	= 	./tests/

CFLAGS	=	-W -Wall -I include/ -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB_PATH)
	gcc -o $(NAME) $(OBJ) -L$(LIB_PATH) -l$(LIB_NAME) $(CFLAGS)

clean:
	make clean -C $(LIB_PATH)
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB_PATH)libmy.a
	rm -f unit_test*

re:	fclean all

tests_run: 
	gcc -lcriterion -o $(UNIT_NAME)1 $(SRC_TEST_1) -L$(LIB_PATH) -l$(LIB_NAME) $(CFLAGS)
	./$(UNIT_NAME)1
	gcc -lcriterion -o $(UNIT_NAME)2 $(SRC_TEST_2) -L$(LIB_PATH) -l$(LIB_NAME) $(CFLAGS)
	./$(UNIT_NAME)2