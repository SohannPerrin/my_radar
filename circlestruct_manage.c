/*
** EPITECH PROJECT, 2022
** circlestruct_manage.c
** File description:
** circle structure funcs
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/circlestruct.h"
#include "include/windowsfuncs.h"

circle_t *add_circle(circle_t* first, int posx, int posy, int radius)
{
    circle_t* current = first;
    circle_t* new_elem = malloc(sizeof(circle_t));

    new_elem->pos.x = posx;
    new_elem->pos.y = posy;
    new_elem->radius = radius;
    new_elem->sector = -1;
    new_elem->next = new_elem->prev = NULL;
    if (first == NULL)
        return (new_elem);
    while (current->next != NULL)
        current = current->next;
    current->next = new_elem;
    new_elem->prev = current;
    return (first);
}

circle_t *rm_circle(circle_t* circle, zone_t *zones)
{
    if (circle->prev != NULL)
        circle->prev->next = circle->next;
    if (circle->next != NULL)
        circle->next->prev = circle->prev;
    free(circle);
}