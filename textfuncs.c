/*
** EPITECH PROJECT, 2022
** textfuncs.c
** File description:
** manages CSFML texts
*/

#include "include/my.h"
#include "include/windowsfuncs.h"

void set_textpos(sfText *text, double posx, double posy)
{
    sfVector2f textpos;
    textpos.x = posx;
    textpos.y = posy;
    sfText_setPosition(text, textpos);
}

void set_textscale(sfText *text, double scalex, double scaley)
{
    sfVector2f textscale;
    textscale.x = scalex;
    textscale.y = scaley;
    sfText_setScale(text, textscale);
}

void set_textfont(sfText *text, char* filename)
{
    sfFont* font = sfFont_createFromFile(filename);
    sfText_setFont(text, font);
}

void set_textcolors(sfText *text, char* data)
{
    int pos = 0;
    sfColor color;
    color.r = makedims(data, &pos);
    color.g = makedims(data, &pos);
    color.b = makedims(data, &pos);
    color.a = makedims(data, &pos);
    sfText_setFillColor(text, color);
}

void set_textcolorfont (sfText *text, char* rgbadata, char* fontname)
{
    set_textcolors(text, rgbadata);
    set_textfont(text, fontname);
}
