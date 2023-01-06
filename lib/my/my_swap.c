/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** swaps thing around
*/

void my_swap(int *a, int *b)
{
    int buffer;

    buffer = *a;
    *a = *b;
    *b = buffer;
}
