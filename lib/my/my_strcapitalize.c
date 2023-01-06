/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** Auto Caps
*/

static int cap2(char *str, int space, int i)
{
    if ((str[i] > 96 && str[i] < 123) && space == 1){
        str[i] = str[i] - 32;
        return (0);
    }
    if (str[i] > 64 && str[i] < 91){
        if (space == 0)
            str[i] = str[i] + 32;
        return (0);
    }
    return (space);
}

char *my_strcapitalize(char *str)
{
    int i;
    int space = 1;

    for (i = 0; str[i] != '\0'; i ++){
        if (!(str[i] > 96 && str[i] < 123) && !(str[i] > 64 && str[i] < 91))
            space = 1;
        space = cap2(str, space, i);
    }
    return (str);
}
