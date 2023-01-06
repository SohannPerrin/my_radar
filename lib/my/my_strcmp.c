/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compares values
*/

int my_strcmp(char const *s1, char const *s2)
{
    int func1 = 0;
    int func2 = 0;
    int i = 0;

    for (i = 0; s1[i] != 0;i ++)
        func1 += (int) s1[i];
    for (i = 0; s2[i] != 0;i ++)
        func2 += (int) s2[i];
    return (func1 - func2);
}
