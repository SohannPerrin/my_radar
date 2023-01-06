/*
** EPITECH PROJECT, 2022
** int_to_str.c
** File description:
** turns an int into an str
*/

#include <stdlib.h>

int my_intlen(int n)
{
    int len = 0;
    int i;
    int rest;

    if (n == 0)
        return (1);
    for (i = 0; n != 0; i++) {
        rest = n % 10;
        n /= 10;
        len ++;
    }
    return (len);
}

char *int_to_str(int i)
{
    char *result;
    int j = 1;
    int len = my_intlen(i);
    result = malloc(sizeof(int) * (len + 1));
    result[len] = 0;
    while (i > 9){
        result[len - j] = ((i % 10) + 48);
        i = i / 10;
        j ++;
    }
    result[len - j] = ((i % 10) + 48);
    if (i == 0)
        result[0] = 48;
    return (result);
}
