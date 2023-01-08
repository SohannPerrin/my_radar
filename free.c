/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** frees mallocs
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/windowsfuncs.h"

void free_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->tex);
    sprite->passed_frames = 0.00;
    free(sprite);
}

void free_win(win_t *win)
{
    sfRenderWindow_destroy(win->window);
    sfText_destroy(win->text);
    sfClock_destroy(win->clock);
    sfSound_destroy(win->sound);
    sfSoundBuffer_destroy(win->sbuff);
    free(win);
}
