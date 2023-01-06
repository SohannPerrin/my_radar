/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** writes strings
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while ((char)str[i] != (char) 0){
        my_putchar(str[i]);
        i ++;
    }
    return (0);
}
