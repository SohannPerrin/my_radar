/*
** EPITECH PROJECT, 2022
** planefuncs.c
** File description:
** plane related functions
*/

#include <fcntl.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/circlestruct.h"
#include "include/windowsfuncs.h"

plane_t *query_plane(zone_t *zones, int i, plane_t *plane)
{
    return (plane);
}

plane_t *colideplanes(zone_t *zones, int i, circle_t *c_first, plane_t *plane)
{
    plane_t *elem = plane->next;
    circle_t *c_elem = c_first;

    while (c_elem != NULL){
        if (round_square(plane->pos, c_elem) == 1)
            return (plane);
        c_elem = c_elem->next;
    }
    while (elem != NULL){
        if (square_intersects(plane->pos, elem->pos) == 1){
            plane = rm_plane(plane);
            elem = rm_plane(elem);
            zones[i].first = elem;
            return (elem);
        }
        elem = elem->next;
    }
    plane = query_plane(zones, i, plane);
    return (plane);
}

void check_done(zone_t *zones, int i, plane_t *elem, win_t *win)
{
    while (elem != NULL) {
        if (elem->delay <= win->time_passed / 25){
            elem->pos.x += (elem->speed.x / 25) * win->frame_passed;
            elem->pos.y += (elem->speed.y / 25) * win->frame_passed;
        }
        if (((elem->pos.x - elem->speed.x < elem->dest.x && elem->pos.x >=
        elem->dest.x) || (elem->pos.x - elem->speed.x > elem->dest.x &&
        elem->pos.x <= elem->dest.x) || (elem->pos.y - elem->speed.y >
        elem->dest.y && elem->pos.y <= elem->dest.y) || (elem->pos.y -
        elem->speed.y < elem->dest.y && elem->pos.y >= elem->dest.y)) &&
        (elem->delay <= win->time_passed / 25)){
            zones[i].first = elem = rm_plane(elem);
        } else
            elem = elem->next;
    }
}

void moveplanes(zone_t *zones, circle_t *c_first, win_t *win)
{
    int i;

    for (i = 0; i <= zones[0].size; i ++) {
        plane_t *elem = zones[i].first;
        while (elem != NULL) {
            elem = colideplanes(zones, i, c_first, elem);
            elem = elem->next;
        }
        elem = zones[i].first;
        check_done(zones, i, elem, win);
    }
}
