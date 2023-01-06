/*
** EPITECH PROJECT, 2022
** windowfuncs.h
** File description:
** windowfuncs.h
*/

#include "struct.h"

#ifndef WINDOWFUNCS_H_
    #define WINDOWFUNCS_H_

    win_t setwin(int width, int height, int res);
    void make_anim(sprite_t* sprite, anim_t* ani, char* data);
    void create_music(win_t *win, char *filepath);
    void setsprite(sprite_t *sprite, char *spritefiles, double sizex,\
    double sizey);
    void framepassed(win_t *win);
    void rollsprite(sprite_t *sprite, win_t *win, int isanim);
    void isgameover(win_t *win, sprite_t *sprite, sprite_t *sprite2);
    void free_music(win_t *win);
    void free_sprite(sprite_t *sprite);
    void free_win(win_t *win);
    void checkhit(sprite_t *sprite, win_t *win);
    void moveling(sprite_t *sprite, win_t *win);
    void roll_anim(win_t *win, sprite_t* obj);
    void setspritepos(sprite_t *sprite, double posx, double posy);
    void movesprite(sprite_t *sprite, win_t *win, double x, double y);
    void setspritescale(sprite_t *sprite, double scalex, double scaley);
    void set_textpos(sfText *text, double posx, double posy);
    void set_textfont(sfText *text, char* filename);
    int makedims(char* data,int* pos);
    void set_textcolors(sfText *text, char* data);
    void set_textscale(sfText *text, double posx, double posy);
    void draw4(sprite_t *sprite, win_t *win);
    void setspriteorigin(sprite_t *sprite, double posx, double posy);
    void draw3(win_t *win, sfSprite *sprite1, sfText *sprite2,\
    sfText *sprite3);
    void displayfunc(win_t *win);
    int get_score(char *filepath);
    int makehigh(char *filepath, int score);

#endif /* WINDOWFUNCS_H_ */
