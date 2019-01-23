/*
** EPITECH PROJECT, 2018
** my_compute_things.c
** File description:
** Functions about calculating stuff
*/

int my_compute_power_rec(int nb, int p)
{
    long long res = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    res = nb * my_compute_power_rec(nb, p - 1);
    if (res > 2147483647)
        return (0);
    else
        return (res);
}

int my_compute_square_root(int nb)
{
    int i = 1;
    int result = 1;
    int return_value = 0;

    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (nb);
    if (nb > 46340 * 46340)
        return (0);
    while (result < nb) {
        i++;
        result = i * i;
    }
    return_value = i;
    if (return_value * return_value == nb) {
        return (return_value);
    } else {
        return (0);
    }
}

int my_is_prime(int nb)
{
    int i = 3;

    if (nb == 2147483647)
        return (1);
    if ((nb < 2) || (nb % 2 == 0))
        return (0);
    while (i < nb) {
        if (nb % i == 0)
            return (0);
        if ((i * i) > nb)
            return (1);
        i = i + 2;
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        return (2);
    if (nb > 2147483629)
        return (2147483647);
    if (my_is_prime(nb) == 1)
        return (nb);
    return (my_find_prime_sup(nb + 1));
}
