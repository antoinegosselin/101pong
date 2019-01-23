/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** Functions about swapping stuff
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

void my_swap_string_values(char **s1, char **s2)
{
    char *temp = *s1;

    *s1 = *s2;
    *s2 = temp;
}
