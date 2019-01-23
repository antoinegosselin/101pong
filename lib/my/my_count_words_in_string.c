/*
** EPITECH PROJECT, 2018
** my_count_words_in_string.c
** File description:
** Counts the number of words inside a given string
*/

#include "my.h"

int my_count_words_in_string(char const *str, int str_length)
{
    int word_count = 0;

    for (int i = 0; i < str_length; i++) {
        if (!i && my_char_isalphanum(str[i]) == 1)
            word_count++;
        if (i && my_char_isalphanum(str[i]) && !my_char_isalphanum(str[i - 1]))
            word_count++;
    }
    return (word_count);
}
