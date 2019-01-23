/*
** EPITECH PROJECT, 2018
** my_isneg.c
** File description:
** Regroups functions that knows about negative numbers
*/

#include "my.h"

int my_put_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}

int my_isneg(int n)
{
    if (n < 0)
        return (1);
    else
        return (0);
}
