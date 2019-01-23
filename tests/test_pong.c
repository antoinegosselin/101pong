/*
** EPITECH PROJECT, 2018
** test_pong.c
** File description:
** Criterion tests for pong
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "pong.h"

void redirect_criterion(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(pong, normal_usage)
{
    char *argv[8] = {"./101pong", "1", "3", "5", "7", "9", "-2", "4"};
    coordinates_t pos0 = get_coordinates(argv, 1);
    coordinates_t post = get_coordinates(argv, 4);

    redirect_criterion();
    pong(pos0, post, my_getnbr(argv[7]));
    cr_assert_stdout_eq_str("The velocity vector of the ball is:\n(6.00, 6.00, -7.00)\nAt time t + 4, ball coordinates will be:\n(31.00, 33.00, -30.00)\nThe ball won't reach the bat.\n");
}

Test(pong, another_normal_usage)
{
    char *argv[8] = {"./101pong", "1.1", "3", "5", "-7", "9", "2", "4"};
    coordinates_t pos0 = get_coordinates(argv, 1);
    coordinates_t post = get_coordinates(argv, 4);

    redirect_criterion();
    pong(pos0, post, my_getnbr(argv[7]));
    cr_assert_stdout_eq_str("The velocity vector of the ball is:\n(-8.10, 6.00, -3.00)\nAt time t + 4, ball coordinates will be:\n(-39.40, 33.00, -10.00)\nThe incidence angle is:\n16.57 degrees");
}

Test(pong, speed_vector_altitude_null)
{
    char *argv[8] = {"./101pong", "2", "5", "5", "5", "1", "5", "4"};
    coordinates_t pos0 = get_coordinates(argv, 1);
    coordinates_t post = get_coordinates(argv, 4);

    redirect_criterion();
    pong(pos0, post, my_getnbr(argv[7]));
    cr_assert_stdout_eq_str("The velocity vector of the ball is:\n(3.00, -4.00, 0.00)\nAt time t + 4, ball coordinates will be:\n(17.00, -15.00, 5.00)\nThe ball won't reach the bat.\n");
}