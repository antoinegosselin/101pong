/*
** EPITECH PROJECT, 2018
** test_wrong_usage.c
** File description:
** Criterion tests for wrong usages of pong
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "pong.h"

const char *usage = "USAGE\n      ./101pong x0 y0 z0 x1 y1 z1 n\n\nDESCRIPTION\n      x0    ball abscissa at time t - 1\n      y0    ball ordinate at time t - 1\n      z0    ball altitude at time t - 1\n      x1    ball abscissa at time t\n      y1    ball ordinate at time t\n      z1    ball altitude at time t\n      n     time shift (greater than or equal to zero, interger)\n\n";

void redirect_criterion(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(pong, negative_n)
{
    char *argv[8] = {"./101pong", "1", "3", "5", "7", "9", "-2", "-4"};

    redirect_criterion();
    if (my_str_isnum(argv[7]) == 0)
        print_usage();
    cr_assert_stdout_eq_str(usage);
}

Test(pong, n_not_a_number)
{
    char *argv[8] = {"./101pong", "1", "3", "5", "7", "9", "-2", "a"};

    redirect_criterion();
    if (my_str_isnum(argv[7]) == 0)
        print_usage();
    cr_assert_stdout_eq_str(usage);
}

Test(pong, wierd_n)
{
    char *argv[8] = {"./101pong", "1", "3", "5", "7", "9", "-2", "123a"};

    redirect_criterion();
    if (my_str_isnum(argv[7]) == 0)
        print_usage();
    cr_assert_stdout_eq_str(usage);
}