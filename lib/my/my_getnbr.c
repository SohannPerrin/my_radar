/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** takes first number
*/

static int getnbr2(char const *str,unsigned int *numbers)
{
    int isneg = 0;
    int result = 0;

    if (numbers[0] > 0){
        if ((char)str[(numbers[0] - 1)] == 45){
            isneg = 1;
        }
    }
    switch (isneg){
        case 1:
            return (result - numbers[2]);
            break;
        default:
            if (numbers[2] < 2147483648){
                return (numbers[2]);
            }
            return (0);
    }
}

int my_getnbr(char const *str)
{
    unsigned int numbers[4], *a, *b, *c;

    a = &numbers[0];
    b = &numbers[1];
    c = &numbers[3];
    numbers[0] = numbers[2] = numbers[3] = 0;
    while (((char)str[*a] < 48 || str[*a] > 57) && (char)str[*a] != 0){
        numbers[0] ++;
    }
    numbers[1] = numbers[0];
    while ((char) str[*b] > 46 && (char) str[*b] < 58 && (char) str[*b] != 0){
        if ((*c == 10 && (numbers[2] / 100000000) % 10 > 50) || *c > 10){
            return (0);
        }
        numbers[2] = (numbers[2] * 10) + ((int)(str[numbers[1]])-48);
        numbers[1] ++;
        numbers[3] ++;
    }
    return (getnbr2(str, numbers));
}
