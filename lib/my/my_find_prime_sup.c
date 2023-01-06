/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** finds a high prime
*/

static int recursprime2(int nb, int depth)
{
    if (depth == 2){
        return (1);
    }
    if (nb % depth == 0){
        return (0);
    }
    return (recursprime2(nb, depth - 1));
}

static int my_is_prime2(int nb)
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
    recursprime2(nb, nb - 1);
}

int my_find_prime_sup(int nb)
{
    if (my_is_prime2(nb) == 1){
        return (nb);
    }
    return (my_find_prime_sup(nb + 1));
}
