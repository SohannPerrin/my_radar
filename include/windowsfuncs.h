/*
** EPITECH PROJECT, 2022
** windowfuncs.h
** File description:
** windowfuncs.h
*/

#include "struct.h"

#ifndef WINDOWFUNCS_H_
    #define WINDOWFUNCS_H_

    win_t *setwin(char *name, int width, int height, int res);
    void make_anim(win_t *win, anim_t *ani, sprite_t* sprite, char* data);
    void create_music(win_t *win, char *filepath);
    sprite_t *setsprite(char *spritefiles, double sizex, double sizey,
    int tile);
    void framepassed(win_t *win);
    void free_music(win_t *win);
    void free_sprite(sprite_t *sprite);
    void free_win(win_t *win);
    void checkhit(sprite_t *sprite, win_t *win);
    void roll_anim(win_t *win, sprite_t* obj);
    void setspritepos(sprite_t *sprite, double posx, double posy);
    void movesprite(sprite_t *sprite, win_t *win, double x, double y);
    void setspritescale(sprite_t *sprite, double scalex, double scaley);
    void set_textpos(sfText *text, double posx, double posy);
    void set_textfont(sfText *text, char* filename);
    int makedims(char* data,int* pos);
    void set_textcolors(sfText *text, char* data);
    void set_textscale(sfText *text, double sizex, double sizey);
    void setspriteorigin(sprite_t *sprite, double posx, double posy);
    void displayfunc(win_t *win);
    int get_score(char *filepath);
    void setwin2(win_t *win);
    int makehigh(char *filepath, int score);
    void set_anim_to(win_t *win, sprite_t *sprite, int frame);
    void set_textcolorfont (sfText *text, char* rgbadata, char* fontname);
    void setspriterect(sprite_t *sprite, char* data, int width, int height);

#endif /* WINDOWFUNCS_H_ */
