/*
** EPITECH PROJECT, 2022
** circlefuncs.c
** File description:
** circle funcs
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/circlestruct.h"
#include "include/windowsfuncs.h"

plane_t *makeplane(char* data, plane_t *first)
{
    int pos = 2;
    plane_t* current = first;
    plane_t* new_elem = malloc(sizeof(plane_t));

    new_elem->pos.x = makedims(data, &pos);
    new_elem->pos.y = makedims(data, &pos);
    new_elem->dest.x = makedims(data, &pos);
    new_elem->dest.y = makedims(data, &pos);
    new_elem->speed = makedims(data, &pos);
    new_elem->delay = makedims(data, &pos);
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

int setplane(char* data, plane_t *first)
{
    int i = 1, elems = 0;
    for (i = 1; data[i] != '\0'; i ++){
        if (data[i] != 32 && data[i] != 9 && data[i] != 10 &&
        (data[i] < 47 || data[i] > 58))
            elems = 7;
        if (data[i] == 32 || data[i] == 9)
            elems += 1;
    }
    if (elems != 6){
        write(2, "invalid instruction file\n", 25);
        return (84);
    }
    first = makeplane(data, first);
    return (0);
}

int settower(char* data, circle_t *first)
{
    int i = 1, elems = 0, pos = 2;
    if (data[0] != 'T')
        elems = 4;
    for (i = 1; data[i] != '\0'; i ++){
        if (data[i] != 32 && data[i] != 9 && data[i] != 10 &&
        (data[i] < 47 || data[i] > 58))
            elems = 4;
        if (data[i] == 32 || data[i] == 9)
            elems += 1;
    }
    if (elems != 3){
        write(2, "invalid instruction file\n", 25);
        return (84);
    }
    first = add_circle(first, makedims(data, &pos), makedims(data, &pos),
    makedims(data, &pos));
    return (0);
}

sfCircleShape *make_circle(float posx, float posy, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, radius);
    sfVector2f pos = (sfVector2f) {posx, posy};
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, sfGreen);
    sfColor color = (sfColor) {0, 0, 0, 0};
    sfCircleShape_setFillColor(circle, color);
    return (circle);
}
