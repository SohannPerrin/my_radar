/*
** EPITECH PROJECT, 2022
** circlestruct.h
** File description:
** contains sprite info
*/

#ifndef CIRCLESTRUCT_H_
    #define CIRCLESTRUCT_H_

    #include "my.h"

    typedef struct circle{
        sfVector2f pos;
        float radius;
        struct circle* next;
        struct circle* prev;
    }circle_t;

    typedef struct plane{
        sfFloatRect hitbox;
        sfVector2f pos;
        sfVector2f dest;
        sfVector2f speed;
        int i_speed;
        int delay;
        int sector;
        unsigned char is_tower;
        struct plane* next;
        struct plane* prev;
    }plane_t;

    typedef struct zone{
        sfFloatRect area;
        int size;
        int num;
        plane_t *first;
        circle_t *f_circle;
    }zone_t;

#endif /* CIRCLESTRUCT_H_ */
