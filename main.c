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
    zone_t zones[4 * 4];
    subdivide_screen(3, zones, c_first);
    while (p_first != NULL)
        p_first = locate_plane(zones, p_first);
    return (0);
}

int setinfo(FILE *fd, char *filepath)
{
    size_t len = 0;
    int seen, errval = 0;
    circle_t *c_first = NULL;
    plane_t *p_first = NULL;
    char* buff = NULL;
    if (fd == -1){
        write(2, "file: '", 6);
        write(2, filepath, my_strlen(filepath));
        write(2, "' not found\n", 12);
        return (84);
    }
    while ((seen = getline(&buff, &len, fd)) != -1){
        if (buff[0] == 'A'){
            errval = setplane(buff, p_first);
        } else
            errval = settower(buff, c_first);
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
ipt\n   path_to_script    The path to the script file.\n\nOPTIONS\n  -h       \
     print the usage and quit.\n\nUSER INTERACTIONS\n  'L' key        enable/d\
isable hitboxes and areas.\n  'S' key        enable/disable sprites.", 348);
        return (0);
    }
    FILE *fd = fopen(av[1], "r");
    int errval = setinfo(fd, av[1]);
    fclose(fd);
    return(errval);
}
