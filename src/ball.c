/*
** EPITECH PROJECT, 2018
** duck.c
** File description:
** print the duck
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

window_t initialize_ball(void)
{
    window_t ball;

    ball.texture = sfTexture_createFromFile("files/ball.png", NULL);
    ball.sprite = sfSprite_create();
    return (ball);
}

sfVector2f print_ball(sfRenderWindow *window, sfVector2f ball_speed,
                                    sfVector2f ball_position, window_t ball)
{
    ball_position.x = ball_position.x + ball_speed.x;
    ball_position.y = ball_position.y + ball_speed.y;
    sfSprite_setTexture(ball.sprite, ball.texture, sfTrue);
    sfSprite_setPosition(ball.sprite, ball_position);
    sfRenderWindow_drawSprite(window, ball.sprite, NULL);
    return (ball_position);
}