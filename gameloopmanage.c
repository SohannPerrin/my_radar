/*
** EPITECH PROJECT, 2022
** gameloopmanage.c
** File description:
** functions managing the gameloop
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/windowsfuncs.h"

void framepassed(win_t *win)
{
    win->frame_passed = 0;
    int tot = sfClock_getElapsedTime(win->clock).microseconds;
    while (tot >= 40000){
        tot -= 40000;
        win->frame_passed += 1;
        win->time_passed += 1;
    }
    sfClock_restart(win->clock);
}

void movesprite(sprite_t *sprite, win_t *win, double x, double y)
{
    sprite->movment.x = (x * win->frame_passed);
    sprite->movment.y = (y * win->frame_passed);
    sfSprite_move(sprite->sprite, sprite->movment);
}

void scalesprite(sprite_t *sprite, win_t *win, double x, double y)
{
    sprite->scale_change.x = (x * win->frame_passed);
    sprite->scale_change.y = (y * win->frame_passed);
    sfSprite_scale(sprite->sprite, sprite->scale_change);
}

void rotatesprite(sprite_t *sprite, win_t *win, double angle)
{
    sprite->direction = (angle * win->frame_passed);
    sfSprite_rotate(sprite->sprite, sprite->direction);
}
