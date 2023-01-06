/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** makes squares but doesn't round
*/

int rec(int nb,int iter)
{
    unsigned int test = iter * iter;

    if (nb == test){
        return (iter);
    }
    if (test > nb){
        return (0);
    }
    return (rec(nb, iter + 1));
}

int my_compute_square_root(int nb)
{
    if (nb <= 0){
        return (0);
    }
    if (nb == 1){
        return (1);
    }
    return (rec(nb, 1));
}
