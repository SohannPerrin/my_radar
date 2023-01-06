/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** counts to n then compares
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int func1 = 0;
    int func2 = 0;
    int i = 0;

    for (i = 0; s1[i] != 0 || i + 1 <= n; i ++)
        func1 += (int) s1[i];
    for (i = 0; s2[i] != 0 || i + 1 <= n; i ++)
        func2 += (int) s2[i];
    return (func1 - func2);
}
