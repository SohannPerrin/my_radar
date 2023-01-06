/*
** EPITECH PROJECT, 2022
** windowmanager.c
** File description:
** graphic window
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdlib.h>

win_t setwin(int width, int height, int res)
{
    win_t win;
    win.errval = win.isinit = win.action = win.mpos.x = win.mpos.y = 0;
    win.frame_passed = win.click = win.game_over = 0;
    win.mbox.height = win.mbox.width = 1;
    win.score = 0.00;
    win.clock = sfClock_create();
    win.vmode.width = width;
    win.vmode.height = height;
    win.vmode.bitsPerPixel = res;
    win.window = sfRenderWindow_create(win.vmode, "radar"\
    , sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(win.window, sfTrue);
    sfRenderWindow_setFramerateLimit(win.window, 25);
    sfRenderWindow_clear(win.window, sfBlack);
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
