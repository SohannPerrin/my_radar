/*
** EPITECH PROJECT, 2022
** gameloop.c
** File description:
** manages gameloop
*/

#include <fcntl.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/circlestruct.h"
#include "include/windowsfuncs.h"

int switch_evt(int i)
{
    if (i > 0){
        return (0);
    } else
        return (1);
}

void eventlisten(win_t* win)
{
    win->action = 0;
    while (sfRenderWindow_pollEvent(win->window, &win->event)){
        if (win->event.type == sfEvtClosed){
            win->game_over = 0;
            win->isinit = 0;
            sfRenderWindow_close(win->window);
        }
        if (win->event.type == sfEvtKeyPressed &&
        win->event.key.code == sfKeyL)
            win->vis_hitbox = switch_evt(win->vis_hitbox);
        if (win->event.type == sfEvtKeyPressed &&
        win->event.key.code == sfKeyS)
            win->vis_sprite = switch_evt(win->vis_sprite);
    }
}

void is_game_over(win_t *win, zone_t *zones)
{
    int i = 0;
    int empty = 0;

    for (i = 0; i <= zones[0].size; i++)
        if (zones[i].first == NULL)
            empty += 1;
    if (empty >= (zones[0].size + 1)){
        sfText_setString(win->text,
        "simulation ended, program will end in 5 seconds");
        sfText_setPosition(win->text, (sfVector2f){800, 500});
        while (sfClock_getElapsedTime(win->clock).microseconds < 5000000){
            eventlisten(win);
            sfRenderWindow_drawSprite(win->window, win->bg->sprite, NULL);
            sfRenderWindow_drawText(win->window, win->text, NULL);
            sfRenderWindow_display(win->window);
        }
        sfRenderWindow_close(win->window);
    }
}

int initloop(zone_t *zones, circle_t *c_first, win_t *win, sprite_t *blimp)
{
    double size = 0.02;
    sprite_t *tower = setsprite("sprites/tower.png", 0.10, 0.10, 0);
    setspriteorigin(tower, 50, 414);
    set_textcolorfont(win->text, "255 255 255 255", "font/Z003.ttf");
    sfText_setOutlineColor(win->text, sfBlack);
    sfText_setOutlineThickness(win->text, 1.00);
    while (sfRenderWindow_isOpen(win->window)){
        eventlisten(win);
        framepassed(win);
        sfRenderWindow_drawSprite(win->window, win->bg->sprite, NULL);
        moveplanes(zones, c_first, win);
        drawtowers(win, c_first, tower);
        drawplanes(win, zones, blimp);
        sfText_setString(win->text, int_to_str(win->time_passed / 25));
        sfRenderWindow_drawText(win->window, win->text, NULL);
        is_game_over(win, zones);
        sfRenderWindow_display(win->window);
    }
    return (0);
}
