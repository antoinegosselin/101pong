/*
** EPITECH PROJECT, 2018
** options.c
** File description:
** initialize the options
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

options_t *initialize_options(void)
{
    options_t *game = malloc(sizeof(options_t));

    game->music = 0;
    game->level = 1;
    game->song = sfMusic_createFromFile("files/music.ogg");
    game->music = set_music(game);
    game->pos.x = 425;
    game->pos.y = 275;
    game->score_left = 0;
    game->score_right = 0;
    return (game);
}