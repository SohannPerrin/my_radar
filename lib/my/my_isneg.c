/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** THE BEST desc
*/

void my_putchar(char c);

int my_isneg(int n)
{
    int val = 80;

    if (n < 0){
        val = 78;
    }
    my_putchar(val);
    return (0);
}
