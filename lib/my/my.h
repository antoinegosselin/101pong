/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Header that contains all functions from the library
*/

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
void my_putchar_err(char c);
int my_putstr(char const *str);
int my_putstr_err(char const *str);
int my_put_isneg(int n);
int my_isneg(int n);
int my_char_islower(char const c);
int my_char_isupper(char const c);
int my_char_isnum(char const c);
int my_char_isalphanum(char const c);
int my_char_isprintable(char const c);
char *my_revstr(char *str);
void my_sort_int_array(int *array, int size);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
char *my_str_lowcase(char *str);
char *my_str_upcase(char *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, const char *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, const char *src, int nb);
char *my_strcapitalize(char *str);
char *my_strstr(char *str, char const *to_find);
int my_add(int a, int b);
int my_sub(int a, int b);
int my_mul(int a, int b);
int my_div(int a, int b);
int my_mod(int a, int b);
void my_swap(int *a, int *b);
void my_swap_string_values(char **s1, char **s2);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_put_nbr(int nb);
int my_count_words_in_string(char const *str, int str_length);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
int my_getnbr(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);

#endif
