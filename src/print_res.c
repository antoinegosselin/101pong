/*
** EPITECH PROJECT, 2018
** print_result.c
** File description:
** print the result of our program
*/

#include <math.h>
#include <stdio.h>
#include "my.h"
#include "pong.h"

float const PI = 3.1415926535897932384626433832795028841971693993751058209749;

static float get_angle(coordinates_t speed)
{
    float angle = 0;
    float opp = speed.z;
    float adj = sqrt((speed.x * speed.x) + (speed.y * speed.y));

    if (adj == 0)
        return (90.00);
    angle = opp / adj;
    angle = atan(angle);
    angle = ((angle * 180) / PI);
    if (angle < 0)
        angle = -angle;
    return (angle);
}

static void print_angle(coordinates_t speed, coordinates_t pos2)
{
    float angle = 0;

    if (speed.z == 0) {
        if (pos2.z == 0) {
            my_putstr(")\nThe incidence angle is:\n");
            my_putstr("0.00 degrees\n");
        } else
            my_putstr(")\nThe ball won't reach the bat.\n");
    }
    else if (((pos2.z < 0) && (speed.z < 0)) || ((pos2.z > 0) && (speed.z > 0)))
        my_putstr(")\nThe ball won't reach the bat.\n");
    else {
        angle = get_angle(speed);
        my_putstr(")\nThe incidence angle is:\n");
        printf("%.2f degrees\n", angle);
    }
}

static void put_nbr(int nbr)
{
    if (nbr < 0) {
        nbr = -nbr;
        my_putchar('-');
    }
    my_put_nbr(nbr / 100);
    my_putchar('.');
    if (nbr % 100 < 10)
        my_putchar('0');
    my_put_nbr(nbr % 100);
}

void print_res(coordinates_t speed, coordinates_t position,
                                    coordinates_t pos2, int n)
{
    my_putstr("The velocity vector of the ball is:\n(");
    put_nbr(speed.x);
    my_putstr(", ");
    put_nbr(speed.y);
    my_putstr(", ");
    put_nbr(speed.z);
    my_putstr(")\nAt time t + ");
    my_put_nbr(n);
    my_putstr(", ball coordinates will be:\n(");
    put_nbr(position.x);
    my_putstr(", ");
    put_nbr(position.y);
    my_putstr(", ");
    put_nbr(position.z);
    print_angle(speed, pos2);
}