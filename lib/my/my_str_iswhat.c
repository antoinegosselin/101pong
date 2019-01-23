/*
** EPITECH PROJECT, 2018
** my_str_iswhat.c
** File description:
** Regroups functions about knowing the status of a string
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (!my_char_islower(str[i]))
            return (0);
    }
    return (1);
}

int my_str_isupper(char const *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (!my_char_isupper(str[i]))
            return (0);
    }
    return (1);
}

int my_str_isalpha(char const *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (!(my_char_islower(str[i]) || my_char_isupper(str[i])))
            return (0);
    }
    return (1);
}

int my_str_isnum(char const *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (!my_char_isnum(str[i]))
            return (0);
    }
    return (1);
}

int my_str_isprintable(char const *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (!(str[i] >= 32 && str[i] <= 126))
            return (0);
    }
    return (1);
}
