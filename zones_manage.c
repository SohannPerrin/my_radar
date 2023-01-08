/*
** EPITECH PROJECT, 2022
** zones_manage.c
** File description:
** zoning funcs
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/circlestruct.h"
#include "include/windowsfuncs.h"

zone_t *subdivide_screen(int sub_level, zone_t *zones, circle_t *circle)
{
    int x, y, pos = 0;
    sub_level += 1;
    double dims_x = 1920.00 / (double)(sub_level);
    double dims_y = 1080.00 / (double)(sub_level);
    for (y = 0; y < sub_level; y ++)
        for (x = 0; x < sub_level; x ++) {
            zones[pos].num = pos;
            zones[pos].first = NULL;
            zones[pos].f_circle = circle;
            zones[pos].area.top = dims_y * y;
            zones[pos].area.left = dims_x * x;
            zones[pos].area.width = dims_x;
            zones[pos].area.height = dims_y;
            zones[pos].size = sub_level * sub_level;
            pos += 1;
        }
    zones[zones[0].size].first = NULL;
    zones[zones[0].size].num = zones[0].size;
    zones[zones[0].size].f_circle = circle;
    return (zones);
}

plane_t *locate_plane(zone_t *zones, plane_t *plane)
{
    int i;
    plane_t *n_plane = plane->next;

    for (i = 0; i < zones[0].size; i ++){
        if (vect_in_rect(plane->pos, zones[i].area) == 1)
            break;
    }
    plane->sector = i;
    if (plane->next != NULL)
        plane->next->prev = plane->prev;
    if (plane->prev != NULL){
        plane->prev->next = plane->next;
        plane->prev = NULL;
    }
    plane->next = zones[i].first;
    if (zones[i].first != NULL)
        zones[i].first->prev = plane;
    zones[i].first = plane;
    return (n_plane);
}
