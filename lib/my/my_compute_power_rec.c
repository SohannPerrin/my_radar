/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** powers up
*/

int my_compute_power_rec(int nb, int p)
{
    unsigned long long int nbclone;

    if (p < 0){
        return (0);
    }
    if (nb == 0 || nb == 1 || p == 0){
        return (1);
    }
    nbclone = nb;
    nbclone *= my_compute_power_rec(nb, p - 1);
    if (nbclone > 2147483647){
        return (0);
    }
    return (nbclone);
}
