/*
** EPITECH PROJECT, 2018
** get_coordinates.c
** File description:
** Gets an int out of the given arguments
*/

#include "my.h"
#include "pong.h"

static int get_nbr(char *str)
{
    int nbr = 0;
    int len = my_strlen(str);
    int multipicator = 100;
    int i = 0;

    if (str[0] == '-') {
        multipicator = -multipicator;
        i++;
    }
    for (; i < len; i++) {
        if (multipicator == 10)
            multipicator = multipicator / 10;
        if (str[i] == '.') {
            multipicator = multipicator / 10;
            i++;
        }
        nbr = nbr * 10 + (str[i] - '0');
    }
    return (nbr * multipicator);
}

coordinates_t get_coordinates(char **argv, int n)
{
    coordinates_t coords;

    coords.x = get_nbr(argv[n + 0]);
    coords.y = get_nbr(argv[n + 1]);
    coords.z = get_nbr(argv[n + 2]);
    return (coords);
}