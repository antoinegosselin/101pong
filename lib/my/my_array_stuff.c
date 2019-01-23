/*
** EPITECH PROJECT, 2018
** my_array_stuff.c
** File description:
** Functions about doing stuff with arrays
*/

#include <stdlib.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}

char **my_str_to_word_array(char const *str)
{
    int pos[4] = { 0, 0, 0, 0 };
    int word_count = my_count_words_in_string(str, my_strlen(str));
    char **return_array = malloc(sizeof(char *) * (word_count + 1));

    while (pos[2] < word_count) {
        while (my_char_isalphanum(str[pos[0]]) == 0)
            pos[0]++;
        pos[1] = pos[0];
        while (my_char_isalphanum(str[pos[0]]) == 1)
            pos[0]++;
        return_array[pos[2]] = malloc(sizeof(char) * (pos[0] - pos[1] + 1));
        for (pos[3] = 0; pos[1] < pos[0]; pos[3]++)
            return_array[pos[2]][pos[3]] = str[pos[1]++];
        return_array[pos[2]++][pos[3]] = '\0';
    }
    return_array[pos[2]] = malloc(sizeof(int));
    return_array[pos[2]] = 0;
    return (return_array);
}
