/*
** EPITECH PROJECT, 2018
** my_strstuffmore.c
** File description:
** More functions about strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';
    return (dest);
}

char *my_strncat(char *dest, const char *src, int nb)
{
    int dest_length = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';
    return (dest);
}

char *my_strcapitalize(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (i == 0 && my_char_islower(str[i]))
            str[i] -= 32;
        if (i != 0 && str[i - 1] == ' ' && my_char_islower(str[i]))
            str[i] -= 32;
        if (i != 0 && str[i - 1] == '+' && my_char_islower(str[i]))
            str[i] -= 32;
        if (i != 0 && str[i - 1] == '-' && my_char_islower(str[i]))
            str[i] -= 32;
        if (i && my_char_isalphanum(str[i - 1]) && my_char_islower(str[i]))
            str[i] -= 32;
    }
    return (str);
}

static int compare_str(char *str, char const *to_find, int i, int length)
{
    for (int j = 0; j < length; j++) {
        if (str[i] == to_find[j])
            i++;
        else
            return (0);
    }
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int str_length = my_strlen(str);
    int to_find_length = my_strlen(to_find);

    for (int i = 0; i < str_length; i++) {
        if (compare_str(str, to_find, i, to_find_length) != 0)
            return (str + i);
    }
    return ('\0');
}
