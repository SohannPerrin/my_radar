/*
** EPITECH PROJECT, 2022
** windowmanager.c
** File description:
** graphic window
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/windowsfuncs.h"
#include <stdlib.h>

static void makewinshapes(win_t *win)
{
    sfColor aqua = (sfColor) {117, 255, 216, 255};
    sfColor transp_aqua = (sfColor) {117, 255, 216, 50};
    sfColor purple = (sfColor) {193, 16, 255, 255};
    sfColor transp_purple = (sfColor) {193, 16, 255, 50};
    win->circ_box = sfCircleShape_create();
    sfCircleShape_setOutlineColor(win->circ_box, aqua);
    sfCircleShape_setFillColor(win->circ_box, transp_aqua);
    sfCircleShape_setOutlineThickness(win->circ_box, 1.00);
    win->rect_box = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(win->rect_box, purple);
    sfRectangleShape_setFillColor(win->rect_box, transp_purple);
    sfVector2f size = (sfVector2f) {20, 20};
    sfRectangleShape_setSize(win->rect_box, size);
    sfVector2f origin = (sfVector2f) {10, 10};
    sfRectangleShape_setOrigin(win->rect_box, origin);
    sfRectangleShape_setOutlineThickness(win->rect_box, 1.00);
}

win_t *setwin(char *name, int width, int height, int res)
{
    win_t *win = malloc(sizeof(win_t));
    win->errval = win->isinit = win->action = win->mpos.x = win->mpos.y = 0;
    win->frame_passed = win->click = win->game_over = win->time_passed = 0;
    win->mbox.height = win->mbox.width = win->vis_hitbox = win->vis_sprite = 1;
    win->clock = sfClock_create();
    win->text = sfText_create();
    win->vmode.width = width;
    win->vmode.height = height;
    win->vmode.bitsPerPixel = res;
    win->window = sfRenderWindow_create(win->vmode, name
    , sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win->window, 25);
    sfRenderWindow_clear(win->window, sfBlack);
    makewinshapes(win);
    return (win);
}

void create_music(win_t *win, char *filepath)
{
    win->music = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(win->music, sfTrue);
    sfMusic_play(win->music);
}

void free_music(win_t *win)
{
    sfMusic_stop(win->music);
    sfMusic_destroy(win->music);
}

void displayfunc(win_t *win)
{
    sfRenderWindow_display(win->window);
    win->click = 0;
}
