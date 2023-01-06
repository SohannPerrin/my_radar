/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** dups a str
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *res;
    int len = 0;
    int i;

    while (src[len] != '\0')
        len ++;
    res = malloc(1 * len);
    for (i = 0; src[i] != '\0'; i ++)
        res[i] = src[i];
    res[i] = '\0';
    return (res);
}
