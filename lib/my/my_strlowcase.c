/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** makes the letters smol
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    for (i = 0; str[i] != 0; i ++) {
        if (str[i] > 64 && str[i] < 91)
            str[i] = (char) str[i] + (char) 32;
    }
    return (str);
}
