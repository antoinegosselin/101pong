/*
** EPITECH PROJECT, 2018
** usage.c
** File description:
** print the usage of our program
*/

#include "my.h"

int print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("      ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("      x0    ball abscissa at time t - 1\n");
    my_putstr("      y0    ball ordinate at time t - 1\n");
    my_putstr("      z0    ball altitude at time t - 1\n");
    my_putstr("      x1    ball abscissa at time t\n");
    my_putstr("      y1    ball ordinate at time t\n");
    my_putstr("      z1    ball altitude at time t\n");
    my_putstr("      n     time shift (greater than or");
    my_putstr(" equal to zero, interger)\n\n");
    return (84);
}