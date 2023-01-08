/*
** EPITECH PROJECT, 2022
** listfuncs.c
** File description:
** draws functions associated to chained lists
*/

#include <fcntl.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/circlestruct.h"
#include "include/windowsfuncs.h"

static void does_plane_draw(win_t *win, plane_t *elem, sprite_t *blimp)
{
    if (elem->delay <= win->time_passed / 25) {
        if (win->vis_sprite == 1)
            sfRenderWindow_drawSprite(win->window, blimp->sprite, NULL);
        if (win->vis_hitbox == 1)
            sfRenderWindow_drawRectangleShape(win->window, win->rect_box, NULL);
    }
}

void drawplanes(win_t *win, zone_t *zones, sprite_t *blimp)
{
    int i;
    sfVector2f pos;

    for (i = 0; i <= zones[0].size; i ++) {
        plane_t *elem = zones[i].first;
        while (elem != NULL) {
            sfSprite_setPosition(blimp->sprite, elem->pos);
            setspritescale(blimp,
            0.01 * (elem->pos.y / 50), 0.01 * (elem->pos.y / 50));
            sfRectangleShape_setPosition(win->rect_box, elem->pos);
            does_plane_draw(win, elem,blimp);
            elem = elem->next;
        }
    }
}

void drawtowers(win_t *win, circle_t *c_first, sprite_t *tower)
{
    circle_t *elem = c_first;
    while (elem != NULL) {
        setspritescale(tower,
        0.01 *(elem->pos.y / 60) + 0.05, 0.01 * (elem->pos.y / 60) + 0.05);
        sfSprite_setPosition(tower->sprite, elem->pos);
        sfCircleShape_setPosition(win->circ_box, elem->pos);
        sfCircleShape_setRadius(win->circ_box, (float) elem->radius);
        sfVector2f rad =
        (sfVector2f) {(float) elem->radius, (float) elem->radius};
        sfCircleShape_setPointCount(win->circ_box, (size_t) (elem->radius));
        sfCircleShape_setOrigin(win->circ_box , rad);
        if (win->vis_hitbox == 1)
            sfRenderWindow_drawCircleShape(win->window, win->circ_box, NULL);
        if (win->vis_sprite == 1)
            sfRenderWindow_drawSprite(win->window, tower->sprite, NULL);
        elem = elem->next;
    }
}
