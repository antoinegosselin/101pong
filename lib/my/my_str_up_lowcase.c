/*
** EPITECH PROJECT, 2018
** my_str_up_lowcase.c
** File description:
** Functions about putting lower/uppercase char in upper/lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (my_char_isupper(str[i]))
            str[i] += 32;
    }
    return (str);
}

char *my_strupcase(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (my_char_islower(str[i]))
            str[i] -= 32;
    }
    return (str);
}
