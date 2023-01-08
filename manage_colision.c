/*
** EPITECH PROJECT, 2022
** manage_colision.c
** File description:
** manages colisions
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/circlestruct.h"
#include "include/windowsfuncs.h"

int vect_in_rect(sfVector2f vect, sfFloatRect rect)
{
    if (vect.x > rect.left && vect.x < (rect.left + rect.width)
    && vect.y > rect.top && vect.y < (rect.top + rect.height))
        return (1);
    return (0);
}

int square_intersects(sfVector2f sqr1, sfVector2f sqr2)
{
    if ((sqr1.x - sqr2.x <= 40 && sqr1.x - sqr2.x >= -40) &&
    (sqr1.y - sqr2.y <= 40 && sqr1.y - sqr2.y >= -40))
        return (1);
    return (0);
}

int round_square(sfVector2f sqr, circle_t *circ)
{
    double dist = sqrt(pow((sqr.x - circ->pos.x), 2.00) +
    pow((sqr.y - circ->pos.y), 2.00));
    sfVector2f line =
    (sfVector2f) {sqr.x - circ->pos.x, sqr.y - circ->pos.y};
    sfVector2f unit_vect = (sfVector2f) {line.x / dist, line.y / dist};
    if (circ->radius < dist){
        unit_vect.x *= circ->radius;
        unit_vect.y *= circ->radius;
    } else
        return (1);
    sfVector2f point =
    (sfVector2f) {circ->pos.x + unit_vect.x, circ->pos.y + unit_vect.y};
    sfFloatRect square = (sfFloatRect) {sqr.x - 10, sqr.y - 10, 20, 20};
    return (vect_in_rect(point, square));
}
