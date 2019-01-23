/*
** EPITECH PROJECT, 2018
** my_operations.c
** File description:
** Simple functions that does operations
*/

#include <stdlib.h>

int my_add(int a, int b)
{
    int result = a + b;

    return (result);
}

int my_sub(int a, int b)
{
    int result = a - b;

    return (result);
}

int my_mul(int a, int b)
{
    int result = a * b;

    return (result);
}

int my_div(int a, int b)
{
    int result;

    if (b == 0)
        result = a + 1;
    else
        result = a / b;
    return (result);
}

int my_mod(int a, int b)
{
    int result;

    if (b == 0)
        result = a + 1;
    else
        result = a % b;
    return (result);
}