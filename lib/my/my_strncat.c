/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** catenate 2 at n
*/

char *my_strncat(char *dest, char const *src, int n)
{
    int len_dest;
    int len_src;

    while (dest[len_dest] != 0)
        len_dest ++;
    for (len_src = 0; src[len_src] != '\0' && len_src < n; len_src ++)
        dest[len_dest + len_src] = src[len_src];
    if (len_src >= n)
        dest[len_dest + len_src] = '\0';
    return (dest);
}
