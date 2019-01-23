/*
** EPITECH PROJECT, 2018
** pong.c
** File description:
** do the caculs of the pong
*/

#include "my.h"
#include "pong.h"

void pong(coordinates_t pos1, coordinates_t pos2, int n)
{
    coordinates_t speed;
    coordinates_t position;

    speed.x = pos2.x - pos1.x;
    speed.y = pos2.y - pos1.y;
    speed.z = pos2.z - pos1.z;
    position.x = (pos2.x + (speed.x * n));
    position.y = (pos2.y + (speed.y * n));
    position.z = (pos2.z + (speed.z * n));
    print_res(speed, position, pos2, n);
}