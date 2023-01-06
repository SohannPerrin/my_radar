/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** expresso reverso
*/

char *my_revstr(char *str)
{
    int i = 0;
    int len = 0;
    char buffer;
    char buffer2;

    while (str[len] != '\0')
        len ++;
    len --;
    for (i ; i <= len - i; i ++) {
        buffer = str[len - i];
        buffer2 = str[i];
        str[len - i] = buffer2;
        str[i] = buffer;
    }
    return (str);
}
