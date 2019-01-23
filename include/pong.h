/*
** EPITECH PROJECT, 2018
** pong.h
** File description:
** functions of pong
*/

#ifndef PONG_H_
#define PONG_H_

typedef struct coordinates_s {
    int x;
    int y;
    int z;
} coordinates_t;

int print_usage(void);
void pong(coordinates_t pos1, coordinates_t pos2, int n);
void print_res(coordinates_t speed, coordinates_t position,
                                    coordinates_t pos2, int n);
coordinates_t get_coordinates(char **argv, int n);

#endif
