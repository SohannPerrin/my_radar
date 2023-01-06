/*
** EPITECH PROJECT, 2022
** my_stupcase.c
** File description:
** MAKES THE TEXT YELL
*/

char *my_strupcase(char *str)
{
    int i = 0;

    for (i = 0; str[i] != 0; i ++) {
        if (str[i] > 96 && str[i] < 123)
            str[i] = (char) str[i] - (char) 32;
    }
    return (str);
}
