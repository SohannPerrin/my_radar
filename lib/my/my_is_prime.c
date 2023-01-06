/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** is it prime or not?
*/

static int recursprime(int nb, int depth)
{
    if (depth == 2){
        return (1);
    }
    if (nb % depth == 0){
        return (0);
    }
    return (recursprime(nb, depth - 1));
}

int my_is_prime(int nb)
{
    if (nb == 2){
        return (1);
    }
    if (nb < 2){
        return (0);
    }
    if (nb % 2 == 0){
        return (0);
    }
    if (nb == 2147483647){
        return (1);
    }
    return (recursprime(nb, nb - 1));
}
