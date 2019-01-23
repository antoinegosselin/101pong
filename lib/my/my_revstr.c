/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** Function that reverses a given string
*/

#include "my.h"

static int get_remaining_swaps(int str_length)
{
    if (str_length % 2 == 0)
        return (str_length / 2);
    else
        return ((str_length - 1) / 2);
}

char *my_revstr(char *str)
{
    int str_length = my_strlen(str);
    int remaining_swaps = get_remaining_swaps(str_length);
    int right_side = str_length - 1;
    char swapping_var;

    for (int left_side = 0; remaining_swaps > 0; left_side++) {
        swapping_var = str[left_side];
        str[left_side] = str[right_side];
        str[right_side] = swapping_var;
        right_side--;
        remaining_swaps--;
    }
    return (str);
}
