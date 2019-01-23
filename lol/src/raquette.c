/*
** EPITECH PROJECT, 2018
** raquette.c
** File description:
** init and print the raquette
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

raq_pos_t init_raquette_pos(int x)
{
    raq_pos_t raquette;

    raquette.x = x;
    raquette.y_high = 225;
    raquette.y_low = 375;
    return (raquette);
}

window_t init_raquette(void)
{
    window_t raquette;

    raquette.texture = sfTexture_createFromFile("files/raquette.png", NULL);
    raquette.sprite = sfSprite_create();
    return (raquette);
}

void print_raquettes(sfRenderWindow *window, window_t raquette_gauche,
                        window_t raquette_droite,
                        sfVector2f raquette_gauche_position,
                        sfVector2f raquette_droite_position)
{
    sfSprite_setTexture(raquette_gauche.sprite, raquette_gauche.texture, sfTrue);
    sfSprite_setPosition(raquette_gauche.sprite, raquette_gauche_position);
    sfRenderWindow_drawSprite(window, raquette_gauche.sprite, NULL);
    sfSprite_setTexture(raquette_droite.sprite, raquette_droite.texture, sfTrue);
    sfSprite_setPosition(raquette_droite.sprite, raquette_droite_position);
    sfRenderWindow_drawSprite(window, raquette_droite.sprite, NULL);
}