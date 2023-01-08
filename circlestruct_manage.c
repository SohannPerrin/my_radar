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

circle_t *add_circle(circle_t* first, char *data)
{
    circle_t* current = first;
    circle_t* new_elem = malloc(sizeof(circle_t));
    int pos = 2;

    new_elem->pos.x = makedims(data, &pos);
    new_elem->pos.y = makedims(data, &pos);
    new_elem->radius = makedims(data, &pos) * 1920 / 100;
    new_elem->next = new_elem->prev = NULL;
    if (first == NULL)
        return (new_elem);
    while (current->next != NULL)
        current = current->next;
    current->next = new_elem;
    new_elem->prev = current;
    return (first);
}

circle_t *rm_circle(circle_t* circle)
{
    circle_t *first = circle;

    while (first->prev != NULL)
        first = first->prev;
    if (circle->prev != NULL)
        circle->prev->next = circle->next;
    if (circle->next != NULL)
        circle->next->prev = circle->prev;
    if (circle->prev == NULL)
        first = circle->next;
    free(circle);
    return (first);
}

plane_t *rm_plane(plane_t *plane)
{
    plane_t *first = plane;

    while (first->prev != NULL)
        first = first->prev;
    if (plane->prev != NULL)
        plane->prev->next = plane->next;
    if (plane->next != NULL)
        plane->next->prev = plane->prev;
    if (plane->prev == NULL)
        first = plane->next;
    free(plane);
    return (first);
}
