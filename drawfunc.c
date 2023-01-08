/*
** EPITECH PROJECT, 2022
** drawfunc.c
** File description:
** draws sprite
*/

#include "include/windowsfuncs.h"
#include "include/struct.h"
#include "include/my.h"
#include <stdlib.h>

sprite_t *setsprite(char *spritefiles, double sizex, double sizey, int tile)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->is_spawn = 0;
    sprite->scale.x = sizex;
    sprite->scale.y = sizey;
    sprite->tex = sfTexture_createFromFile(spritefiles, NULL);
    if (tile == 1)
        sfTexture_setRepeated(sprite->tex, sfTrue);
    sprite->sprite = sfSprite_create();
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfSprite_setTexture(sprite->sprite, sprite->tex, sfTrue);
    return (sprite);
}

void setspritepos(sprite_t *sprite, double posx, double posy)
{
    sfVector2f spos;

    spos.x = posx;
    spos.y = posy;
    sfSprite_setPosition(sprite->sprite, spos);
}

void setspritescale(sprite_t *sprite, double scalex, double scaley)
{
    sfVector2f sscale;

    sscale.x = scalex;
    sscale.y = scaley;
    sfSprite_setScale(sprite->sprite, sscale);
}

void setspriteorigin(sprite_t *sprite, double posx, double posy)
{
    sfVector2f spos;

    spos.x = posx;
    spos.y = posy;
    sfSprite_setOrigin(sprite->sprite, spos);
}

void setspriterect(sprite_t *sprite, char* data, int width, int height)
{
    sfIntRect rect;
    int pos = 0;

    rect.left = makedims(data, &pos);
    rect.top = makedims(data, &pos);
    rect.width = width;
    rect.height = height;
    sfSprite_setTextureRect(sprite->sprite, rect);
}
