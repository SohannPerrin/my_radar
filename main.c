/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <fcntl.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/circlestruct.h"
#include "include/windowsfuncs.h"

int setzone(circle_t *c_first, plane_t *p_first)
{
    anim_t blimp_anim[8];
    zone_t zones[2];
    subdivide_screen(0, zones, c_first);
    while (p_first != NULL){
        p_first = locate_plane(zones, p_first);
    }
    win_t *win = setwin("radar", 1920, 1080, 32);
    win->bg = setsprite("sprites/map2.png", 1.00, 1.00, 0);
    sprite_t *blimp = setsprite("sprites/blimp.png", 0.10, 0.10, 0);
    setspriteorigin(blimp, 763.00, 378.00);
    make_anim(win, blimp_anim, blimp,
    "1526 756 8 0 0 1527 0 0 756 1527 756 0 1512 1527 1512 0 2268 1527 2268");
    return (initloop(zones, c_first, win, blimp));
}

int setinfo(FILE *fd, char *filepath)
{
    size_t len = 0;
    int seen, errval = 0;
    circle_t *c_first = NULL;
    plane_t *p_first = NULL;
    char* buff = NULL;
    if (fd == NULL){
        write(2, "file: '", 6);
        write(2, filepath, my_strlen(filepath));
        write(2, "' not found\n", 12);
        return (84);
    }
    while ((seen = getline(&buff, &len, fd)) != -1){
        if (buff[0] == 'A'){
            errval = setplane(buff, &p_first);
        } else
            errval = settower(buff, &c_first);
        if (errval != 0)
            return (errval);
    }
    return (setzone(c_first, p_first));
}

int main(int ac, char **av)
{
    if (ac != 2){
        write(2, "my_radar takes one argument\nretry with -h\n", 42);
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h'){
        write(1, "/***************************\\\n|Air trafic simulation panel\
|\n\\***************************/\n\nUSAGE\n  ./my_radar [OPTIONS] path_to_scr\
ipt\n   path_to_script    The path to the script file.\n\nOPTIONS\n  \
-h            print the usage and quit.\n\nUSER INTERACTIONS\n  'L' ke\
y        enable/disable hitboxes and areas.\n  'S' key        enable/disable s\
prites.", 348);
        return (0);
    }
    FILE *fd = fopen(av[1], "r");
    int errval = setinfo(fd, av[1]);
    if (fd != NULL)
        fclose(fd);
    return (errval);
}
