/*
** EPITECH PROJECT, 2018
** speed.c
** File description:
** change the speed of the ball
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

sfVector2f speed_change(sfRenderWindow *window, sfVector2f speed,
                        sfVector2f *ball_position, options_t *game,
                        sfVector2f raquette_gauche_position,
                        sfVector2f raquette_droite_position)
{
    if (ball_position->y <= 570)
        speed.y = speed.y * -1;
    if (ball_position->y >= 0)
        speed.y = speed.y * -1;
    if (ball_position->x >= 870) {
        if (ball_position->y >= (raquette_droite_position.y - 15) && ball_position->y <= (raquette_droite_position.y + 165))
            speed.x = speed.x * -1;
        else {
            set_score(window, 1, game);
            ball_position->x = 450 - 15;
            ball_position->y = 300 - 15;
            speed.x = -4 * game->level;
            speed.y = -4 * game->level;
        }
    }
    if (ball_position->x <= 0) {
        if (ball_position->y >= (raquette_gauche_position.y - 15) && ball_position->y <= (raquette_gauche_position.y + 165))
            speed.x = speed.x * -1;
        else {
            set_score(window, 2, game);
            ball_position->x = 450 - 15;
            ball_position->y = 300 - 15;
            speed.x = 4 * game->level;
            speed.y = 4 * game->level;
        }
    }
    return (speed);
}