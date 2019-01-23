/*
** EPITECH PROJECT, 2018
** my_put_text.c
** File description:
** Regroups functions about displaying text
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

int my_putstr_err(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_err(str[i]);
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb / 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return (0);
}
