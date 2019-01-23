/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function for 101pong_2018
*/

#include "my.h"
#include "pong.h"

int main(int argc, char **argv)
{
    coordinates_t pos0;
    coordinates_t post;

    if (argc != 8 || my_strcmp(argv[1], "-h") == 0)
        return (print_usage());
    pos0 = get_coordinates(argv, 1);
    post = get_coordinates(argv, 4);
    if (my_str_isnum(argv[7]) == 0)
        return (print_usage());
    pong(pos0, post, my_getnbr(argv[7]));
    return (0);
}