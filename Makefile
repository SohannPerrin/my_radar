##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## initializes cat
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

COPIES	=	*~

COPIES2	=	#*#

NAME	=	radar

MAKE	=	make

LIB	=	lib/my/libmy.a

CFLAGS	=	-g -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	princ clean

princ:	$(OBJ)
	cd lib/my/ && $(MAKE)
	rm -f '*.o'
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -lm lib/my/libmy.a

clean:
	rm -f $(OBJ)
	rm -f $(COPIES)
	rm -f $(COPIES2)

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB)

re:     fclean all clean
