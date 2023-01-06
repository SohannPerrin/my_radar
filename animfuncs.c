/*
** EPITECH PROJECT, 2022
** animfuncs.c
** File description:
** fuctions related to animations
*/

#include "include/my.h"
#include "include/struct.h"

void roll_anim(win_t *win, sprite_t* sprite)
{
    sfSprite_setTextureRect(sprite->sprite, sprite->anim[sprite->frame].dims);
    if (sprite->frame == (sprite->anim[sprite->frame].tot - 1)) {
        sprite->frame = 0;
    } else {
        sprite->frame += 1;
        sprite->passed_frames += 0.5;
    }
}

void set_anim_to(win_t *win, sprite_t *sprite, int frame)
{
    while (sprite->frame != frame)
        roll_anim(win, sprite);
}

int makedims(char* data,int* pos)
{
    int dim = 0;
    for (*pos; data[*pos] != ' ' && data[*pos] != '\0' && data[*pos] != '\n'
    ; *pos += 1) {
        dim *= 10;
        dim += (data[*pos] - 48);
    }
    *pos += 1;
    return (dim);
}

void make_anim(win_t *win, anim_t *ani, sprite_t* sprite, char* data)
{
    int pos = 0;
    int i;
    int width = makedims(data, &pos);
    int height = makedims(data, &pos);
    int num = makedims(data, &pos);

    sprite->frame = sprite->passed_frames = 0;
    for (i = 0; i < num; i ++) {
        ani[i].tot = num;
        ani[i].dims.width = width;
        ani[i].dims.height = height;
        ani[i].dims.left = makedims(data, &pos);
        ani[i].dims.top = makedims(data, &pos);
    }
    sprite->anim = ani;
    roll_anim(win, sprite);
    while (sprite->frame != 0)
        roll_anim(win, sprite);
}
