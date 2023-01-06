/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** the most TERRIFIC desc
*/

void my_putchar(char c);

static void numero_dos(int size,long int bignb2)
{
    int currentnb;

    while (size > 1){
        currentnb = bignb2 % 100;
        my_putchar(currentnb);
        bignb2 = (bignb2 / 100);
        size --;
    }
}

int my_put_nbr(int nb)
{
    int size = 1;
    long int bignb = nb;
    long int bignb2 = 0;

    if (nb == 0){
        my_putchar(48);
    }
    if (nb < 0){
        bignb = bignb*(-1);
        my_putchar(45);
    }

    while (bignb > 0){
        bignb2 = bignb2 * 100;
        bignb2 += (bignb % 10)+48;
        size += 1;
        bignb = (bignb / 10);
    }
    numero_dos(size,bignb2);
    return (0);
}
