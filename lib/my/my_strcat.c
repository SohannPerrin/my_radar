/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** catenates 2 strings
*/

#include <stdlib.h>
int my_strlen(char const *str);

char *my_strcat(char *buff, char *dest, char *src)
{
    int len_dest = 0;
    int len_src = 0;

    buff = malloc(my_strlen(dest) + my_strlen(src));
    while (dest[len_dest] != 0) {
        buff[len_dest] = dest[len_dest];
        len_dest ++;
    }
    for (len_src = 0; src[len_src] != '\0'; len_src ++)
        buff[len_dest + len_src] = src[len_src];
    buff[len_dest + len_src] = '\0';
    return (buff);
}
