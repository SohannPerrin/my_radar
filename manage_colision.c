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

int circle_intersects(sfCircleShape *circ1, sfCircleShape *circ2)
{
    float c1radius = sfCircleShape_getRadius(circ1);
    float c2radius = sfCircleShape_getRadius(circ2);
    sfVector2f c1center;
    c1center.x = sfCircleShape_getPosition(circ1).x + c1radius;
    c1center.y = sfCircleShape_getPosition(circ1).y + c1radius;
    sfVector2f c2center;
    c2center.x = sfCircleShape_getPosition(circ2).x + c2radius;
    c2center.y = sfCircleShape_getPosition(circ2).y + c2radius;
    if (pow((c1center.x - c2center.x), 2.00) + pow((c1center.y - c2center.y),
    2.00) <= pow((c1radius + c2radius), 2.00))
        return (1);
    return (0);
}