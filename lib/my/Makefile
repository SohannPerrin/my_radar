##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makes file
##


SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

COPIES	=	*~

COPIES2	=	#*#

NAME	=	libmy.a

all:	princ clean

princ:	$(OBJ)
	gcc -c $(SRC)
	rm -f '*.o'
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(COPIES)
	rm -f $(COPIES2)
