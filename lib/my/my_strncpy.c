/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** copies n
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int j = 0;
    int sup = 0;

    while ( src[i] != 0)
        i++;
    if ( i + 1 < n)
        sup = n - i;
    while ( j != n - sup){
        dest[j] = src[j];
        j ++;
    }
    while (sup > 0){
        dest[j] = '\0';
        j ++;
        sup --;
    }
    return (dest);
}
